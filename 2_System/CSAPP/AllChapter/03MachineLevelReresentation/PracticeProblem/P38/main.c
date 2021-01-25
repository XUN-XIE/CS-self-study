/*************************************************************************
 @Author: XieXun
 @Created Time : Sat  5 Dec 09:15:27 2020
 @File Name: main.c
 @Description:
 ************************************************************************/

#include <stdio.h>

// i <-- %rdi
// j <-- %rsi
int main()
{
    // leap --> %rdx = 8*i
    // subq --> %rdx = 7*i
    // addq --> %rdx = 7*i+j
    // leap --> %rax = 5*j
    // addq --> %rdi = i+5*j
    //
    // movq --> Q[8*(i+5*j)] + P[8*(7*i+j)]
    // N = 7, M = 5
    printf("Q[8*(i+5*j)] + P[8*(7*i+j)] --> N = 7, M = 5\n");
}
