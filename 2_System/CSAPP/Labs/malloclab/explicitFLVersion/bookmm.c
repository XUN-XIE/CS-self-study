/*
 * mm-naive.c - The fastest, least memory-efficient malloc package.
 * 
 * In this naive approach, a block is allocated by simply incrementing
 * the brk pointer.  A block is pure payload. There are no headers or
 * footers.  Blocks are never coalesced or reused. Realloc is
 * implemented directly using mm_malloc and mm_free.
 *
 * NOTE TO STUDENTS: Replace this header comment with your own header
 * comment that gives a high level description of your solution.
 */
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <unistd.h>
#include <string.h>

#include "mm.h"
#include "memlib.h"

/* single word (4) or double word (8) alignment */
#define ALIGNMENT DSIZE

/* rounds up to the nearest multiple of ALIGNMENT */
#define ALIGN(size) (((size) + (ALIGNMENT-1)) & ~0x7)


#define SIZE_T_SIZE (ALIGN(sizeof(size_t)))
/*********************************************************
 * NOTE TO STUDENTS: Before you do anything else, please
 * provide your team information in the following struct.
 ********************************************************/
team_t team = {
    /* Team name */
    "Pulihser",
    /* First member's full name */
    "XIE XUN",
    /* First member's email address */
    "2320802672@qq.com",
    /* Second member's full name (leave blank if none) */
    "",
    /* Second member's email address (leave blank if none) */
    ""
};

/* begin malloc macros */
// Basic constants and macros
#define WSIZE 4     // word size and header/footer size
#define DSIZE 8
#define CHUNKSIZE (1<<12)       // extend heap by this amount (bytes)

#define MAX(x, y)   ((x) > (y) ? (x) : (y))

// pack a size and allocated bit into a word
#define PACK(size, alloc)   ((size) | (alloc))

// read and wrtie a word at address p
#define GET(p)  (*(unsigned int *)(p))
#define PUT(p, val) (*(unsigned int *)(p) = (val))

// read the size and allocated fields from address p
#define GET_SIZE(p) (GET(p) & ~0x7)
#define GET_ALLOC(p)    (GET(p) & 0x1)

// given block ptr bp, compute address of its header and footer
#define HDRP(bp)    ((char *)(bp) - WSIZE)
#define FTRP(bp)    ((char *)(bp) + GET_SIZE(HDRP(bp)) - DSIZE)

// given block ptr bp, compute address of next and previous block
#define NEXT_BLKP(bp)   ((char *)(bp) + GET_SIZE(((char *)(bp) - WSIZE)))
#define PREV_BLKP(bp)   ((char *)(bp) - GET_SIZE(((char *)(bp) - DSIZE)))

/* end malloc macros */

// global variables
static char *heap_listp = 0;    // pointer to first block

/* Function prototypes for internal helper routines */
 static void *extend_heap(size_t words);
 static void place(void *bp, size_t asize);
 static void *find_fit(size_t asize);
 static void *coalesce(void *bp);
 static void printblock(void *bp); 
 static void checkheap(int verbose);
 static void checkblock(void *bp);


/* 
 * mm_init - initialize the malloc package.
 */
int mm_init(void)
{
    // create the initial empty heap
    if ( ( heap_listp = mem_sbrk(4 * WSIZE) ) == (void *)-1 )
        return -1;
    PUT( heap_listp, 0 );                           // Alignment padding，为了确保 heap_listp 开始的位置，是 8 的倍数！所以这里的 32bits 填充 0
    // prologue and epilogue are used for eliminate the edge conditions during coalescing
    PUT( heap_listp + (1*WSIZE), PACK(DSIZE, 1) );  // Prologue header

    // 这里的 prologue footer 在第一次真正扩建 heap 时，可以被修改吗？？？？？？？？
    PUT( heap_listp + (2*WSIZE), PACK(DSIZE, 1) );  // Prologue footer

    // 从 extend_heap 函数可以看出， 每次扩容 heap 会调整 epilogue header！
    PUT( heap_listp + (3*WSIZE), PACK(0, 1) );      // Epilogue header
    heap_listp += (2*WSIZE);

    // extend the empty heap with a free block of CHUNKSIZE bytes
    if ( extend_heap(CHUNKSIZE / WSIZE) == NULL )
        return -1;
    return 0;
}

/* 
 * mm_malloc - Allocate a block by incrementing the brk pointer.
 *     Always allocate a block whose size is a multiple of the alignment.
 */
void *mm_malloc(size_t size)
{
    size_t asize;
    size_t extendsize;
    char *bp;

    if ( heap_listp == 0)
        mm_init();
    if ( size == 0 )
        return NULL;

    // adjust block size to include overhead and alignment reqs
    if ( size <= DSIZE )
        asize = 2 * DSIZE;
    else
        asize = DSIZE * ( ( size + (DSIZE) + (DSIZE-1) ) / DSIZE );

    // search the free list for a fit
    if ( (bp = find_fit(asize) ) != NULL )
    {
        place(bp, asize);
        return bp;
    }

    // no fit found. get more mempry and place the block
    extendsize = MAX(asize, CHUNKSIZE);
    if ( ( bp = extend_heap( extendsize / WSIZE ) ) == NULL )
        return NULL;
    place(bp, asize);
    return bp;
}

/*
 * mm_free - Freeing a block does nothing.
 */
void mm_free(void *bp)
{
    if (bp == 0)
        return;

    size_t size = GET_SIZE( HDRP(bp) );
    if (heap_listp == 0)
        mm_init();

    PUT( HDRP(bp), PACK(size, 0) );
    PUT( FTRP(bp), PACK(size, 0) );
    coalesce(bp);

}

/*
 * mm_realloc - Implemented simply in terms of mm_malloc and mm_free
 */
void *mm_realloc(void *ptr, size_t size)
{
    void *oldptr = ptr;
    void *newptr;
    size_t copySize;
    
    newptr = mm_malloc(size);
    if (newptr == NULL)
      return NULL;
    copySize = *(size_t *)((char *)oldptr - SIZE_T_SIZE);
    if (size < copySize)
      copySize = size;
    memcpy(newptr, oldptr, copySize);
    mm_free(oldptr);
    return newptr;
}

// coalesce - Boundary tag coalescing. Return ptr to coalesced block
// 从这个合并函数可以看出，每次合并时，并没有修改每一块的 header 和 footer！
// 而只是修改了 合并后 的块 的 header 和 footer
// 因此 在后续的 fit 算法中，需要确保 查找顺序是严格单调的！
static void *
coalesce(void *bp)
{
    size_t prev_alloc = GET_ALLOC( FTRP( PREV_BLKP(bp) ) );
    size_t next_alloc = GET_ALLOC( HDRP( NEXT_BLKP(bp) ) );
    size_t size = GET_SIZE( HDRP(bp) );

    // case 1
    if ( prev_alloc && next_alloc )
        return bp;

    // case 2
    else if ( prev_alloc && !next_alloc )
    {
        size += GET_SIZE( HDRP( NEXT_BLKP(bp) ) );
        PUT( HDRP(bp), PACK(size, 0) );
        // 这里 FTRP 利用了 刚刚修改过的 HDRP 进行计算，所以保证了正确
        PUT( FTRP(bp), PACK(size, 0) );
    }

    // case 3
    else if ( !prev_alloc && next_alloc )
    {
        size += GET_SIZE( HDRP( PREV_BLKP(bp) ) );
        PUT( FTRP(bp), PACK(size, 0) );
        PUT( HDRP( PREV_BLKP(bp) ), PACK(size, 0) );
        bp = PREV_BLKP(bp);
    }

    else 
    {
        size += GET_SIZE( HDRP( NEXT_BLKP(bp) ) ) + GET_SIZE( FTRP( PREV_BLKP(bp) ) );
        PUT( HDRP( PREV_BLKP(bp) ), PACK(size, 0) );
        PUT( FTRP( NEXT_BLKP(bp) ), PACK(size, 0) );
        bp = PREV_BLKP(bp);
    }

    return bp;
}

static void *
extend_heap(size_t words)
{
    char *bp;
    size_t size;

    // allocate an even number of words to maintain alignment
    size = (words % 2) ? (words + 1) * WSIZE : words * WSIZE;
    if ( (long)(bp = mem_sbrk(size)) == -1 )
        return NULL;

    // initialize free block header/footer and the epilogue header
    // 注意这一行，bp 原本是在 epilogue 后面的
    // 使用 HDRP 后，此时 修改的是 旧的 epilogue
    // 不仅如此，另外一个原因是为了 对齐！只有 bp 的header 在 上一个 epilogue里
    // 才能 达到 对齐要求！！！！
    PUT(HDRP(bp), PACK(size, 0));   // free block header
    PUT(FTRP(bp), PACK(size, 0));   // free block footer
    // 以为 旧的 epilogue 帮助 新创建的 block 整体减 1
    // 所以 最后还有 size = 1 的空间，留给 新的 epilogue ！
    PUT(HDRP(NEXT_BLKP(bp)), PACK(0, 1));       // new epilogue header
    // coalesce if the previous block was free
    return coalesce(bp);
}

// place - place block of asize bytes at start of free block bp
//         and split if remainder would be at least minimum block size
//
//      ----spliting----
static void
place(void *bp, size_t asize)
{
    size_t csize = GET_SIZE( HDRP(bp) );

    if ( (csize - asize) >= (2*DSIZE) )
    {
        PUT( HDRP(bp), PACK(asize, 1) );
        PUT( FTRP(bp), PACK(asize, 1) );
        bp = NEXT_BLKP(bp);
        PUT( HDRP(bp), PACK( csize - asize, 0) );
        PUT( FTRP(bp), PACK( csize - asize, 0) );
    }
    else
    {
        PUT( HDRP(bp), PACK(asize, 1) );
        PUT( FTRP(bp), PACK(asize, 1) );
    }
}

// find_fit - Find a fit for a block with asize bytes
static void *
find_fit(size_t asize)
{
    void *bp;

    for ( bp = heap_listp; GET_SIZE( HDRP(bp) ) > 0; bp = NEXT_BLKP(bp) )
    {
        if ( !GET_ALLOC( HDRP(bp) ) && ( asize <= GET_SIZE( HDRP(bp) ) ) )
            return bp;
    }
    return NULL;
}

static void
printblock(void *bp)
{
    size_t hsize, halloc, fsize, falloc;

    checkheap(0);
    hsize = GET_SIZE( HDRP(bp) );
    halloc = GET_ALLOC( HDRP(bp) );
    fsize = GET_SIZE( FTRP(bp) );
    falloc = GET_ALLOC( FTRP(bp) );

    if (hsize == 0)
    {
        printf("%p: EOL\n", bp);
        fflush(stdout);
        return;
    }

    printf("%p: header: [%ld:%c] footer: [%ld:%c]\n", bp,
            hsize, (halloc ? 'a' : 'f'), 
            fsize, (falloc ? 'a' : 'f'));
    fflush(stdout);
}

static void
checkblock(void *bp)
{
    if ( (size_t)bp % 8 )
    {
        printf("\033[41mError: %p is not double word aligned\n\033[0m", bp);
        fflush(stdout);
    }
    if ( GET( HDRP(bp) ) != GET( FTRP(bp) ) )
    {
        printf("\033[41mError: header does not match footer\n\033[0m");
        fflush(stdout);
    }
}

void
checkheap(int verbose)
{
    char *bp = heap_listp;

    if (verbose)
    {
        printf("Heap (%p):\n", heap_listp);
    }

    if ( (GET_SIZE( HDRP(heap_listp) ) != DSIZE) || !GET_ALLOC( HDRP(heap_listp) ) )
    {
        printf("\033[41mBad prologue header\n\033[0m");
    }
    checkblock(heap_listp);

    for ( bp = heap_listp; GET_SIZE( HDRP(bp) ) > 0; bp = NEXT_BLKP(bp) )
    {
        if (verbose)
            printblock(bp);
        checkblock(bp);
    }

    if (verbose)
        printblock(bp);
    if ( (GET_SIZE( HDRP(bp) ) != 0 ) || !(GET_ALLOC( HDRP(bp) ) ) )
        printf("\033[41mBad epilogue header\n\033[0m");
}

void
mm_checkheap(int verbose)
{
    checkheap(verbose);
}

