/*************************************************************************
 @Author: XieXun
 @Created Time : Sat  5 Dec 09:05:16 2020
 @File Name: main.c
 @Description:
 ************************************************************************/

#include <stdio.h>

int main()
{
    printf("P[1]    short   M[xp + 2]   movw 2(%%rdx), %%ax\n");
    printf("P+3+i   short*  xp+6+2i     leap 6(%%rdx, %%rcx, 2), %%rax\n");
    printf("P[6i-5] short   M[xp+12i-10]    movw -10(%%rdx, %%rcx, 12), %%ax\n");
    printf("P[2]    short   M[xp+4]     movw 4(%%rdx), %%ax\n");
    printf("&P[i+2] short*  xp+4i+4     leap 4(%%rdx, %%rcx, 2), %%rax\n");

}
