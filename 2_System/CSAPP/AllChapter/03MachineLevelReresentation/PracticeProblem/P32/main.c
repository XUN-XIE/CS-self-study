/*************************************************************************
 @Author: XieXun
 @Created Time : Sat  5 Dec 08:13:32 2020
 @File Name: main.c
 @Description:
 ************************************************************************/

#include <stdio.h>

int main()
{
    printf("M1  0x400560    callq   10  --- --- 0x7ffffffffe820 --- Call first(10)\n");
    printf("F1  0x400548    lea     10  --- ---                 0x400565     leap for %%rsi\n");
    printf("F2  0x40054c    sub     10  11  ---                 0x400565    sub 1 to %%rdi\n");
    printf("F3  0x400550    callq   9   11  ---                 0x400565    Call last(9, 11)\n");
    printf("L1  0x400540    mov     9   11  ---                 0x400555    mov %%rdi to %%rax\n");
    printf("L2  0x400543    imul    9   11  9                   0x400555    imul %%rsi to %%rax\n");
    printf("L3  0x400547    retq    9   11  99                  0x400555    return from last\n");
    printf("F4  0x400555    retq    9   11  99                  0x400565    return from first\n");
    printf("M2  0x400565    mov     --- --- 99                  ---    move %%rax to %%rdx\n");
}
