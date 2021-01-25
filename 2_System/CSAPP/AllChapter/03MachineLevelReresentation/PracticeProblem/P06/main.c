/*************************************************************************
 @Author: XieXun
 @Created Time : Wed  2 Dec 20:56:07 2020
 @File Name: main.c
 @Description:
 ************************************************************************/

#include <stdio.h>

// %rbx <-- p
// %rdx <-- q
// %rax <-- tmp

int main()
{
    printf("leaq 9(%%rdx), %%rax            q+9\n");
    printf("leaq (%%rdx,%%rbx), %%rax       q+p\n");
    printf("leaq (%%rdx,%%rbx,3), %%rax     q+3*p\n");
    printf("leaq 2(%%rbx,%%rbx,7), %%rax    8*p+2\n");
    printf("leaq 0xE(,%%rdx,3), %%rax       3*q+14\n");
    printf("leaq 6(%%rbx,%%rdx,7), %%rax    p+7*q+6\n");
    
    return 0;
}
