/* 
 * Simple, 32-bit and 64-bit clean allocator based on implicit free
 * lists, first-fit placement, and boundary tag coalescing, as described
 * in the CS:APP3e text. Blocks must be aligned to doubleword (8 byte) 
 * boundaries. Minimum block size is 16 bytes. 
 */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "mm.h"
#include "memlib.h"

#define DEBUG 1
//#define DEBUG_EXTEND 1
//#define DEBUG_PLACE 1
//#define DEBUG_COAL 1
//#define DEBUG_FIT 1

// #define DEBUG_overlap 1
/*********************************************************
 * NOTE TO STUDENTS: Before you do anything else, please
 * provide your team information in the following struct.
 ********************************************************/
team_t team = {
    /* Team name */
    "Pulisher",
    /* First member's full name */
    "XIE XUN",
    /* First member's email address */
    "2320802672@qq.com",
    /* Second member's full name (leave blank if none) */
    "",
    /* Second member's email address (leave blank if none) */
    ""
};

/*
 * If NEXT_FIT defined use next fit search, else use first-fit search 
 */

/* placement policy 
 * you can only set one #define to to use
 * if both of them are commented, it means first fit
 * DON'T set both of them!
 */
// #define NEXT_FIT 1
// #define BEST_FIT 1

/* coalescing policy
 */
// #define LAZY_COAL 1



/* explicit free list
 * changes:
 * free block need to add two words to save pred and succ
 *
 * HDRP and FTRP need to change version for free block
 * but do not need to change for allocated block
 *
 * NEXT_BLKP and PREV_BLKP macros need to change
 *
 * traverse method in function need to change
 *
 */

/* idea to format free list
 *
 * LIFO method with boundary tag(footer)
 * First fit
 * prologue / epilogue ?
 *
 * if no prologue and epilogue
 * boundary free block, pred = NULL, succ = NULL
 *
 * place:
 * first fit, the the most recent freed block is at the beginning of the free list
 * 
 * split:
 * save pred, save succ, decrement size, change header and footer
 *
 * 
 * coalescing:
 * how to traverse if using LIFO?
 * use prologue to start 
 *
 */



/* $begin mallocmacros */
/* Basic constants and macros */
#define WSIZE       4       /* Word and header/footer size (bytes) */ //line:vm:mm:beginconst
#define DSIZE       8       /* Double word size (bytes) */
#define CHUNKSIZE  (1<<12)  /* Extend heap by this amount (bytes) */  //line:vm:mm:endconst 

#define MAX(x, y) ((x) > (y)? (x) : (y))  

/* Pack a size and allocated bit into a word */
#define PACK(size, alloc)  ((size) | (alloc)) //line:vm:mm:pack

/* Read and write a word at address p */
#define GET(p)       (*(unsigned int *)(p))            //line:vm:mm:get
#define PUT(p, val)  (*(unsigned int *)(p) = (unsigned int)(val))    //line:vm:mm:put

/* Read the size and allocated fields from address p */
#define GET_SIZE(p)  (GET(p) & ~0x7)                   //line:vm:mm:getsize
#define GET_ALLOC(p) (GET(p) & 0x1)                    //line:vm:mm:getalloc

/* Given block ptr bp, compute address of its header and footer */
#define ABHDRP(bp)       ((char *)(bp) - WSIZE)                      //line:vm:mm:hdrp
#define ABFTRP(bp)       ((char *)(bp) + GET_SIZE(ABHDRP(bp)) - DSIZE) //line:vm:mm:ftrp
#define FBHDRP(bp)       ((char *)(bp) - 3*WSIZE)
#define FBFTRP(bp)       ((char *)(bp) + GET_SIZE(FBHDRP(bp)) - 4 * WSIZE)

/* Given block ptr bp, and if it is free block, compute the address of its prev and succ */
#define PRED(bp)        ((char *)(bp) - DSIZE)
#define SUCC(bp)        ((char *)(bp) - WSIZE)

/* $end mallocmacros */

/* Global variables */
static char *heap_listp = 0;  /* Pointer to first block */  
#ifdef NEXT_FIT
static char *rover;           /* Next fit rover */
#endif

/* Function prototypes for internal helper routines */
static void *extend_heap(size_t words);
static void place(void *bp, size_t asize);
static void *find_fit(size_t asize);
static void *coalesce(void *bp);
static void printblock(void *bp); 
static void checkheap(int verbose);
static void checkblock(void *bp);
static void printAll(void);
static void *get_prev(void *bp);
/* 
 * mm_init - Initialize the memory manager 
 */
/* $begin mminit */
int mm_init(void) 
{
    /* Create the initial empty heap */
    if ((heap_listp = mem_sbrk(8*WSIZE)) == (void *)-1) //line:vm:mm:begininit
        return -1;
    PUT(heap_listp, 0);                          /* Alignment padding */
    PUT(heap_listp + (1*WSIZE), PACK(4*WSIZE, 1)); /* Prologue header */ 
    PUT(heap_listp + (2*WSIZE), 0);     // pred
    PUT( heap_listp + (3*WSIZE), heap_listp + (8*WSIZE) );     // succ, initialized to epilogue
    PUT(heap_listp + (4*WSIZE), PACK(4*WSIZE, 1)); /* Prologue footer */ 
    PUT(heap_listp + (5*WSIZE), PACK(0, 1));     /* Epilogue header */
    PUT( heap_listp + (6*WSIZE), heap_listp + (4*WSIZE) );     /* Epilogue pred */
    PUT(heap_listp + (7*WSIZE), 0);     /* Epilogue succ */
    //PUT(heap_listp + (8*WSIZE), PACK(4*WSIZE, 1));     /* Epilogue footer */
    heap_listp += (4*WSIZE);                     //line:vm:mm:endinit  
    /* $end mminit */

#ifdef NEXT_FIT
    rover = heap_listp;
#endif
    /* $begin mminit */

    /* Extend the empty heap with a free block of CHUNKSIZE bytes */
    if (extend_heap(CHUNKSIZE/WSIZE) == NULL) 
        return -1;
    return 0;
}
/* $end mminit */

/* 
 * mm_malloc - Allocate a block with at least size bytes of payload 
 */
/* $begin mmmalloc */
void *mm_malloc(size_t size) 
{

#ifdef DEBUG
    printf("\n\n\033[41mmalloc start at very start------------- with request size (%zu)\033[0m\n", size);
    printAll();
#endif

    size_t asize;      /* Adjusted block size */
    size_t extendsize; /* Amount to extend heap if no fit */
    char *bp;      

    /* $end mmmalloc */
    if (heap_listp == 0){
        mm_init();
    }
    /* $begin mmmalloc */
    /* Ignore spurious requests */
    if (size == 0)
        return NULL;

    /* Adjust block size to include overhead and alignment reqs. */
    if (size <= DSIZE)                                          //line:vm:mm:sizeadjust1
        asize = 2*DSIZE;                                        //line:vm:mm:sizeadjust2
    else
        asize = DSIZE * ((size + (DSIZE) + (DSIZE-1)) / DSIZE); //line:vm:mm:sizeadjust3
    
#ifdef DEBUG
    printf("\n\n\033[41mmalloc start with request asize (%zu)\033[0m\n", asize);
    printAll();
#endif
    /* Search the free list for a fit */
    if ( (bp = find_fit(asize)) != NULL ) 
    {  
        ///*
        #ifdef DEBUG
        printf("\n\t\tfit success\n");
        printAll();
        #endif
        //*/
        place(bp, asize);                  
        #ifdef DEBUG
        printf("\n\t\t fit sucess and place over\n");
        printAll();
        #endif
        return bp;
    }

    #ifdef DEBUG
    printf("\n\n\033[42mfind_fit failed\033[0m\n");
    printAll();
    #endif
    /* No fit found. Get more memory and place the block */
    extendsize = MAX(asize,CHUNKSIZE);                 //line:vm:mm:growheap1
    printf("\033[42m extend size [%d]\033[0m\n", extendsize);
    if ((bp = extend_heap(extendsize/WSIZE)) == NULL)  
        return NULL;                                  //line:vm:mm:growheap2
    #ifdef DEBUG
    printf("\n\n\033[43m first find falied, extend over again, start to place\033[0m\n");
    printAll();
    #endif
    place(bp, asize);                                 //line:vm:mm:growheap3
    #ifdef DEBUG
    printf("\n\n\033[43m malloc place over\033[0m\n");
    printAll();
    #endif

    return bp;
} 
/* $end mmmalloc */

/* 
 * mm_free - Free a block 
 */
/* $begin mmfree */
void mm_free(void *bp)
{
    /* $end mmfree */
    if (bp == 0) 
        return;

    /* $begin mmfree */
    size_t size = GET_SIZE( ABHDRP(bp) );
    /* $end mmfree */
    if (heap_listp == 0){
        mm_init();
    }
    /* $begin mmfree */

    // LIFO method
    // change the succ of prologue to the current bp
    // set the succ of current bp to the original succ of prologue
    bp = (char *)(bp) + DSIZE;  // change bp to correct position because it change from allocated block to be free block;
    PUT( FBHDRP(bp), PACK(size, 0));
    PUT( FBFTRP(bp), PACK(size, 0));
    
    void *succ_heap_listp = (void *)GET( SUCC(heap_listp) );
    PUT( SUCC(bp), succ_heap_listp );
    PUT( PRED(succ_heap_listp), bp );

    PUT( SUCC(heap_listp), bp );
    PUT( PRED(bp), heap_listp );

#ifdef LAZY_COAL
#else
    // coalesce function cannot change the position of current bp!!!
    coalesce(bp);
#endif
}

static void *
get_prev(void *bp)
{
    void *prev_footer =  FBHDRP(bp) - WSIZE; 
    int prev_size = GET_SIZE( prev_footer );
    void *prev = (char *)(bp) - prev_size;
    return prev;
}

/* $end mmfree */
/*
 * coalesce - Boundary tag coalescing. Return ptr to coalesced block
 */
/* $begin mmfree */
static void *coalesce(void *bp) 
{
    // 因为使用的是 LIFO method
    // 所以 传入的 bp 的 succ 和 pred 不能改变
    // 一切以 传入的 bp 的 succ 和 pred 为基准，让左右两边的 block 靠拢
    // 要查找的是 物理形式 最紧邻的 block
    // 并不是 链表！
    size_t prev_alloc = GET_ALLOC( FBHDRP(bp) - WSIZE ); // 找到左面block的footer
    size_t next_alloc = GET_ALLOC( FBFTRP(bp) + WSIZE ); // 找到右面block的header
    size_t size = GET_SIZE( FBHDRP(bp) );

#ifdef DEBUG_COAL
    printf("\t\t\tbefore coalescing\n");
    printf("before coalesce bp = [%p]\n", bp);
    printf("coalesced size = [%d]\n\n\n", size);
    printAll();
    printf("\textend start\n");
    #endif
    if (prev_alloc && next_alloc) {            /* Case 1 */
        return bp;
    }

    // 改 pred 不改 succ
    else if (prev_alloc && !next_alloc) {      /* Case 2 */
        void *next = FBFTRP(bp) + 4*WSIZE;
        size += GET_SIZE( FBHDRP(next) );

        PUT( FBHDRP(bp), PACK(size, 0) );
        PUT( FBFTRP(bp), PACK(size, 0) );
/*
        // add PRED and SUCC
        PUT( PRED(bp), PRED(next) );
        PUT( SUCC(bp), SUCC(next) );
*/
        // update the PRED and SUCC of next
        // change the succ of pred of next
        // change the pred of succ of next
        void *succ_next = (void *)GET( SUCC(next) );
        void *pred_next = (void *)GET( PRED(next) );
        PUT( SUCC( pred_next ), succ_next );
        PUT( PRED( succ_next ), pred_next );
    }

    else if (!prev_alloc && next_alloc) {      /* Case 3 */
        void *prev = get_prev(bp);

        size += GET_SIZE( FBHDRP( prev ) );


        PUT( FBFTRP(prev), PACK(size, 0) );
        PUT( FBHDRP(prev), PACK(size, 0) );
        
        void *succ_prev = (void *)GET( SUCC( prev ) );
        void *pred_prev = (void *)GET( PRED( prev ) );
        // prev 的 succ 和 pred 相连
        PUT( SUCC( pred_prev ), succ_prev );
        PUT( PRED( succ_prev ), pred_prev );

        void *succ =  (void *)GET( SUCC( bp ) );
        void *pred =  (void *)GET( PRED( bp ) );
        // bp 的 succ 和 pred 保存到 当前合并块
        PUT( SUCC( prev ), succ );
        PUT( PRED( prev ), pred );

        // prev is existing, no need to change the linkage
        bp = prev;
    }

    else {                                     /* Case 4 */
        // need to change the linkage of next of bp;
        // 链接 next 的 pred 和 succ 在一起
        // 不改变 prev 的 linkage
        void *next =  FBFTRP(bp) + 4*WSIZE;
        void *prev = get_prev(bp);

        size += GET_SIZE( FBHDRP( next ) ) + GET_SIZE( FBHDRP( prev ) );

        PUT( FBHDRP( prev ), PACK(size, 0));
        PUT( FBFTRP( prev ), PACK(size, 0));
        
        // 链接 next 的 pred 和 succ
        void *pred_next = (void *)GET( PRED(next) );
        void *succ_next = (void *)GET( SUCC(next) );
        PUT( SUCC( pred_next ), succ_next );
        PUT( PRED( succ_next ), pred_next );

        // 链接 prev 的 pred 和 succ
        void *succ_prev = (void *)GET( SUCC( prev ) );
        void *pred_prev = (void *)GET( PRED( prev ) );
        // prev 的 succ 和 pred 相连
        PUT( SUCC( pred_prev ), succ_prev );
        PUT( PRED( succ_prev ), pred_prev );

        void *succ =  (void *)GET( SUCC( bp ) );
        void *pred =  (void *)GET( PRED( bp ) );
        // bp 的 succ 和 pred 保存到 当前合并块
        PUT( SUCC( prev ), succ );
        PUT( PRED( prev ), pred );

        bp = prev;
    }
#ifdef DEBUG_COAL
    printf("\t\t\t coalescing over\n");
    printf("coalesced bp = [%p]\n\n\n", bp);
    printf("coalesed together size [%d]\n", size);
    printAll();
    printf("\textend start\n");
    fflush(stdout);
    #endif
    /* $end mmfree */
#ifdef NEXT_FIT
    /* Make sure the rover isn't pointing into the free block */
    /* that we just coalesced */
    if ((rover > (char *)bp) && (rover < NEXT_BLKP(bp))) 
        rover = bp;
#endif
    /* $begin mmfree */
    return bp;
}
/* $end mmfree */

/*
 * mm_realloc - Naive implementation of realloc
 */
void *mm_realloc(void *ptr, size_t size)
{
    size_t oldsize;
    void *newptr;

    /* If size == 0 then this is just free, and we return NULL. */
    if(size == 0) {
        mm_free(ptr);
        return 0;
    }

    /* If oldptr is NULL, then this is just malloc. */
    if(ptr == NULL) {
        return mm_malloc(size);
    }

    newptr = mm_malloc(size);

    /* If realloc() fails the original block is left untouched  */
    if(!newptr) {
        return 0;
    }

    /* Copy the old data. */
    oldsize = GET_SIZE(ABHDRP(ptr));
    if(size < oldsize) oldsize = size;
    memcpy(newptr, ptr, oldsize);

    /* Free the old block. */
    mm_free(ptr);

    return newptr;
}

/* 
 * mm_checkheap - Check the heap for correctness
 */
void mm_checkheap(int verbose)  
{ 
    checkheap(verbose);
}

/* 
 * The remaining routines are internal helper routines 
 */

/* 
 * extend_heap - Extend heap with free block and return its block pointer
 */
/* $begin mmextendheap */
static void *extend_heap(size_t words) 
{
    char *bp;
    size_t size;

#ifdef DEBUG_EXTEND
    printf("\t\t\tbefore enxtend, words = [%d]\n", words);
    printAll();
    printf("\textend start\n");
    #endif
    /* Allocate an even number of words to maintain alignment */
    size = (words % 2) ? (words+1) * WSIZE : words * WSIZE; //line:vm:mm:beginextend
    if ((long)(bp = mem_sbrk(size)) == -1)  
        return NULL;                                        //line:vm:mm:endextend

    /* Initialize free block header/footer and the epilogue header */
    char *endp = bp + size;
    // bp now after the epilogue, there are 3 * WSIZE bytes in epilogue(no footer) and need to change them all
    PUT( FBHDRP(bp), PACK(size, 0));         /* Free block header */   //line:vm:mm:freeblockhdr
    // do not need to change pred!
    PUT( SUCC(bp), endp ); // succ set to value of epilogue!
    PUT( FBFTRP(bp), PACK(size, 0));         /* Free block footer */   //line:vm:mm:freeblockftr

    /* new epilogue */
    PUT( FBHDRP(endp), PACK(0, 1) ); /* New epilogue header */ //line:vm:mm:newepihdr
    PUT( PRED(endp), bp );   // pred
    PUT( SUCC(endp), 0 );    // succ
#ifdef DEBUG_EXTEND
    printf("\t\t\textend over, size = [%d]\n", size);
    printAll();
    printf("\textend over over\n");
    #endif
    /* Coalesce if the previous block was free */
    return coalesce(bp);                                          //line:vm:mm:returnblock
}
/* $end mmextendheap */

/* 
 * place - Place block of asize bytes at start of free block bp 
 *         and split if remainder would be at least minimum block size
 */
/* $begin mmplace */
/* $begin mmplace-proto */
static void place(void *bp, size_t asize)
/* $end mmplace-proto */
{
    size_t csize = GET_SIZE( FBHDRP(bp) );   
    #ifdef DEBUG_PLACE
        printf("\n\t\t\tinternal place start\n");
        //printf("newP = [%p]\n", newP);
        printf("csize = %u, asize = %u, csize - asize = %u\n", csize, asize, PACK(csize - asize, 0));
        printAll();
        printf("\n\t\t\t internal place start\n");
    #endif

    // 要确保 差 大于 4*WSIZE，因为 free block overhead 为 4*WSIZE
    // 加上 alignment requirement， 因此改成 大于等于 6*WSIZE
    if ( (csize - asize) >= (3*DSIZE) ) { 
        // 剩下的 free block
        // set header and footer
        void *newP = (char *)(bp) + asize;
        printf("\n\n\033[44mnewP = [%p]\n", newP);
        printf("csize - asize = [%d]\033[0m\n\n\n", csize - asize);
        PUT( FBHDRP(newP), PACK(csize-asize, 0) );
        PUT( FBFTRP(newP), PACK(csize-asize, 0) );
        // set pred and succ
        PUT( PRED(newP), GET( PRED(bp) ) );
        PUT( SUCC(newP), GET( SUCC(bp) ) );

        // update the pred and succ of bp
        void *pred_bp = (void *)GET( PRED(bp) );
        void *succ_bp = (void *)GET( SUCC(bp) );
        PUT( SUCC( pred_bp ), newP );
        PUT( PRED( succ_bp ), newP );

        // finally update the bp to allocated block
        PUT( FBHDRP(bp), PACK(asize, 1) );
        PUT( FBFTRP(bp), PACK(asize, 1) );
     
    }
    else { 
        // link pred and succ of bp
        void *pred_bp = (void *)GET( PRED(bp) );
        void *succ_bp = (void *)GET( SUCC(bp) );
        PUT( SUCC( pred_bp ), succ_bp );
        PUT( PRED( succ_bp ), pred_bp );

        PUT( FBHDRP(bp), PACK(csize, 1) );
        PUT( FBFTRP(bp), PACK(csize, 1) );
    }
    #ifdef DEBUG_PLACE
        printf("\n\t\t\tinternal place over\n");
        //printf("newP = [%p]\n", newP);
        printf("csize = %u, asize = %u, csize - asize = %u\n", csize, asize, PACK(csize - asize, 0));
        printAll();
        printf("\n\t\t\t internal place over\n");
    #endif
}
/* $end mmplace */

/* 
 * find_fit - Find a fit for a block with asize bytes 
 */
/* $begin mmfirstfit */
/* $begin mmfirstfit-proto */
static void *find_fit(size_t asize)
/* $end mmfirstfit-proto */
{
    /* $end mmfirstfit */
    #ifdef DEBUG_FIT
        printf("\n\t\t\t before first fit\n");
        printf(" asize = %u\n\n", asize );
        printAll();
        printf("\n\t first fit start\n");
    #endif


#ifdef NEXT_FIT 
    /* Next fit search */
    char *oldrover = rover;

    /* Search from the rover to the end of list */
    for ( ; GET_SIZE(HDRP(rover)) > 0; rover = NEXT_BLKP(rover))
        if (!GET_ALLOC(HDRP(rover)) && (asize <= GET_SIZE(HDRP(rover))))
            return rover;

    /* search from start of list to old rover */
    for (rover = heap_listp; rover < oldrover; rover = NEXT_BLKP(rover))
        if (!GET_ALLOC(HDRP(rover)) && (asize <= GET_SIZE(HDRP(rover))))
            return rover;

    return NULL;  /* no fit found */
#else 
    #ifdef BEST_FIT
        void *bp;

        void *best_bp = NULL;
        int first_time = 1;
        for (bp = heap_listp; GET_SIZE(HDRP(bp)) > 0; bp = NEXT_BLKP(bp)) 
        {
            if (!GET_ALLOC(HDRP(bp)) && (asize <= GET_SIZE(HDRP(bp))))
            {
                if (first_time)
                {
                    best_bp = bp;
                    first_time = 0;
                    continue;
                }

                if ( GET_SIZE( HDRP(bp) ) < GET_SIZE( HDRP(best_bp) ) )
                    best_bp = bp;
            } 
        }
        return best_bp;
    #else
        /* $begin mmfirstfit */
        /* First-fit search */
        void *bp;

        for (bp = heap_listp; GET_SIZE( FBHDRP(bp) ) > 0; bp = (void *)GET( SUCC(bp) ) ) {
            if ( !GET_ALLOC( FBHDRP(bp) ) && ( asize <= GET_SIZE( FBHDRP(bp ) ) ) ) {
    #ifdef DEBUG_FIT
        printf("\n\t\t\t after first fit success, bp = [%p]\n", bp);
        printAll();
        printf("\n\t first fit over\n");
    #endif
                return bp;
            }
        }
//printf("no fit\n");
    #ifdef DEBUG_FIT
        printf("\n\t\t\t after first fit failed\n");
        printAll();
        printf("\n\t first fit over\n");
    #endif
        return NULL; /* No fit */
    #endif
#endif
}
/* $end mmfirstfit */

static void printblock(void *bp) 
{
    /*
    size_t hsize, halloc, fsize, falloc;

    checkheap(0);
    hsize = GET_SIZE( HDRP(bp) );
    halloc = GET_ALLOC( HDRP(bp) );  
    fsize = GET_SIZE( FTRP(bp) );
    falloc = GET_ALLOC( FTRP(bp) );  

    if (hsize == 0) {
        printf("%p: EOL\n", bp);
        return;
    }

    printf("%p: header: [%d:%c] footer: [%d:%c]\n", bp, 
           hsize, (halloc ? 'a' : 'f'), 
           fsize, (falloc ? 'a' : 'f')); 
           */
}

static void checkblock(void *bp) 
{
    /*
    if ((size_t)bp % 8)
        printf("\033[41mError: %p is not doubleword aligned\n\033[0m", bp);
    if (GET(HDRP(bp)) != GET(FTRP(bp)))
        printf("\033[41mError: header does not match footer\n\033[0m");
        */
}

// * checkheap - Minimal check of the heap for consistency 
void checkheap(int verbose) 
{
    /*
    char *bp = heap_listp;

    if (verbose)
        printf("Heap (%p):\n", heap_listp);

    if ((GET_SIZE(HDRP(heap_listp)) != DSIZE) || !GET_ALLOC(HDRP(heap_listp)))
        printf("Bad prologue header\n");
    checkblock(heap_listp);

    for (bp = heap_listp; GET_SIZE(HDRP(bp)) > 0; bp = NEXT_BLKP(bp)) {
        if (verbose) 
            printblock(bp);
        checkblock(bp);
    }

    if (verbose)
        printblock(bp);
    if ((GET_SIZE(HDRP(bp)) != 0) || !(GET_ALLOC(HDRP(bp))))
        printf("Bad epilogue header\n");
        */
}
       
void
printAll(void)
{
    char *cursor = heap_listp - 3*WSIZE;
    printf("Prologue Header [%p]\n", cursor);
    printf("Prologue Payload [%p]\n", heap_listp);
    printf("PRED [%p]\n", (void *)GET( (char *)cursor + WSIZE ) );
    printf("SUCC [%p]\n", (void *)GET( (char *)cursor + 2*WSIZE ) );
    printf("Prologue Footer [%p]\n\n\n", (char *)cursor + 3*WSIZE);
    cursor = heap_listp + WSIZE;
    for (; GET_SIZE( cursor ) > 0;)
    {
        // if allocated block
        if ( GET_ALLOC(cursor) )
        {
            printf("Pointer Header [%p]\n", cursor);
            printf("Payload [%p]\n", (char *)cursor + WSIZE);
            printf("size = [%d]\n", GET_SIZE( cursor ) );
            printf("alloc = [%d]\n", GET_ALLOC( cursor ) );
            cursor = ABFTRP( ( (char *)cursor + WSIZE) );
            printf("Pointer Footer [%p]\n", cursor );

            cursor = (char *)(cursor) + WSIZE;
            printf("next cursor(Header) [%p]\n", cursor);
            printf("next size [%d]\n", GET_SIZE( cursor ));
            printf("\n");
        }
        else
        {
            printf("Pointer Header [%p]\n", cursor);
            cursor = (char *)(cursor) + 3*WSIZE;
            printf("Payload [%p]\n", cursor);
            printf("size = [%d]\n", GET_SIZE( FBHDRP( cursor ) ) );
            printf("alloc = [%d]\n", GET_ALLOC( cursor ) );
            printf("PRED --> [%p]\n", (void *)GET( PRED( cursor ) ) );
            printf("SUCC --> [%p]\n", (void *)GET( SUCC( cursor ) ) );
            printf("Pointer Footer [%p]\n", FBFTRP( cursor ) );

            cursor = FBFTRP( cursor ) + WSIZE;
            printf("next cursor(Header) [%p]\n", cursor);
            printf("next size [%d]\n", GET_SIZE( cursor ));
            printf("\n");
        }
    }



    printf("\n----------last block-----------\n");
        if ( GET_ALLOC(cursor) )
        {
            if ( GET_SIZE( cursor ) == 0 )
            {
                printf("Epilogue Header [%p]\n", cursor);
                printf("Epilogue Payload [%p]\n", (cursor + 3*WSIZE ) );
            printf("alloc = [%d]\n", GET_ALLOC( cursor ) );
                printf("PRED [%p]\n", (void *)GET( (char *)cursor + WSIZE ) );
                printf("SUCC [%p]\n", (void *)GET( (char *)cursor + 2*WSIZE ) );
            }
            else
            {
                printf("Pointer Header [%p]\n", cursor);
                printf("Payload [%p]\n", (char *)cursor + WSIZE);
                printf("size = [%d]\n", GET_SIZE( cursor ) );
                printf("alloc = [%d]\n", GET_ALLOC( cursor ) );
                cursor = ABFTRP( ( (char *)cursor + WSIZE) );
                printf("Pointer Footer [%p]\n", cursor );

                cursor = (char *)(cursor) + WSIZE;
                printf("next cursor(Header) [%p]\n", cursor);
                printf("next size [%d]\n", GET_SIZE( cursor ));
                printf("\n");
            }
        }
        else
        {
            printf("Pointer Header [%p]\n", cursor);
            cursor = (char *)(cursor) + 3*WSIZE;
            printf("Payload [%p]\n", cursor);
            printf("size = [%d]\n", GET_SIZE( FBHDRP( cursor ) ) );
            printf("alloc = [%d]\n", GET_ALLOC( cursor ) );
            printf("PRED --> [%p]\n", (void *)GET( PRED( cursor ) ) );
            printf("SUCC --> [%p]\n", (void *)GET( SUCC( cursor ) ) );
            printf("Pointer Footer [%p]\n", FBFTRP( cursor ) );

            cursor = FBFTRP( cursor ) + WSIZE;
            printf("next cursor(Header) [%p]\n", cursor);
            printf("next size [%d]\n", GET_SIZE( cursor ));
            printf("\n");
        }


}
