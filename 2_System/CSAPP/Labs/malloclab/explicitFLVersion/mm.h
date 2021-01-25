#include <stdio.h>

extern int mm_init (void);
extern void *mm_malloc (size_t size);
extern void mm_free (void *ptr);
extern void *mm_realloc(void *ptr, size_t size);
extern void mm_checkheap(int verbose);

/* 
 * Students work in teams of one or two.  Teams enter their team name, 
 * personal names and login IDs in a struct of this
 * type in their bits.c file.
 */
typedef struct {
    char *teamname; /* ID1+ID2 or ID1 */
    char *name1;    /* full name of first member */
    char *id1;      /* login ID of first member */
    char *name2;    /* full name of second member (if any) */
    char *id2;      /* login ID of second member */
} team_t;

extern team_t team;

/*
1. 用隐式free list。因为显式free list 要创建 list，管理起来会更复杂一点儿
2. 算法细节没有敲定，比如 fit，合并

init    --> increase heap
malloc  --> split
free    --> Coalescing

3. check 需要自己实现
4. 可调用的系统函数，只有五个
5. 不能自定义 数据结构
6. 多用 macro 处理 pointer casting
*/


