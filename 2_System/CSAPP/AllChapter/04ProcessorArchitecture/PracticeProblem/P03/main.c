/*************************************************************************
 @Author: XieXun
 @Created Time : Thu 10 Dec 12:04:26 2020
 @File Name: main.c
 @Description:
 ************************************************************************/

#include <stdio.h>

int main()
{
    // irmovq $8,%r8    Constant 8
    // irmovq $1,%r9    Constant 1
    // addq %r8,%rdi
    // subq %r9,%rsi
    printf("delete line 2 and line 3\n");
    printf("change line 8 and line 9 to:\n");
    printf("iaddq   $8, %%rdi\n");
    printf("iaddq   $0xffffffffffffffff, %%rsi\n");
}
