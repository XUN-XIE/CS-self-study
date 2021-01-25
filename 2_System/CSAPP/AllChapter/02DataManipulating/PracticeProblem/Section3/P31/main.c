/*************************************************************************
 @Author: XieXun
 @Created Time : Fri 27 Nov 22:49:35 2020
 @File Name: main.c
 @Description:
 ************************************************************************/

#include <stdio.h>

/* Determine whether arguments can be added without overflow */
/* WARNING: This code is buggy. */
int tadd_ok(int x, int y) {
    int sum = x+y;
    return (sum-x == y) && (sum-y == x);
}

int main()
{
    printf("因为这并不能检测overflow，这个return无论何时返回都是1 ！\n");
}
