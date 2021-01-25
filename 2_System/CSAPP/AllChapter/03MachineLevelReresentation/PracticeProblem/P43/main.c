/*************************************************************************
 @Author: XieXun
 @Created Time : Sat  5 Dec 09:57:12 2020
 @File Name: main.c
 @Description:
 ************************************************************************/

#include <stdio.h>

typedef union {
    struct 
    {
        long   u;   // 0
        short  v;   // 8
        char   w;   // 10
    } t1; 
    struct          
    {
        int a[2];   // 0
        char *p;    // 8
    } t2;
} u_type;

#define type long
#define expr up->t1.u

void get(u_type *up, type *dest)
{
    *dest = expr;
}

int main()
{
    // 注意 这个最外层是个 union！所以索取 t2 的时候重新计算 地址
    printf("up->t1.u    long    movq (%%rdi), %%rax      movq %%rax, (%%rsi)\n");

    printf("up->t1.v    short   movw 8(%%rdi), %%ax      movw %%ax, (%%rsi)\n");

    printf("&up->ti.w   char*   leap 10(%%rdi), %%rax    leap (%%rax), (%%rsi)\n");
    
    printf("up->t2.a    int*    leap (%%rdi), %%rax    leap (%%rax), (%%rs)    i\n");

    printf("up->t2.a[up->t1.u]  int         ");
    printf("movq (%%rdi), %%rcx      movl (%%rdi, %%rcx, 4), %%rax     movl %%eax, (%%rsi)\n");
    //
    // 最后一步不对，内存传内存错的，得先传到 寄存器！
    // movb (%%rax), (    %%rsi)
    printf("*up->t2.p   char    leap 8(%%rdi), %%rax    movb (%%rax), %%al,     movb %%al, (%%rsi)\n");
}
