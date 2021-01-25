/*************************************************************************
 @Author: XieXun
 @Created Time : Wed  2 Dec 20:56:07 2020
 @File Name: main.c
 @Description:
 ************************************************************************/

#include <stdio.h>


//  void decode1(long *xp, long *yp, long *zp)
//  xp in %rdi, yp in %rsi, zp in %rdx

// decode1:
// movq    (%rdi), %r8
// movq    (%rsi), %rcx
// movq    (%rdx), %rax
// movq    %r8, (%rsi)
// movq    %rcx, (%rdx)
// movq    %rax, (%rdi)
// ret
// 
void decode1(long *xp, long *yp, long *zp)
{
    long tmp = *xp;
    long tmp2 = *yp;
    long tmp3 = *zp;
    
    *yp = tmp;
    *zp = tmp2;
    *xp = tmp3;

    return;
}

int main()
{
    printf("the assemble code is shown as below:\n");
    printf("movq    (%%rdi), %%rax\n"
        "movq    (%%rsi), %%rcx\n"
        "movq    (%%rdx), %%r8\n"
        "movq    %%rax, (%%rsi)\n"
        "movq    %%rcx, (%%rdx)\n"
        "movq    %%r8, (%%rdi)\n"
        "retq\n");
}
