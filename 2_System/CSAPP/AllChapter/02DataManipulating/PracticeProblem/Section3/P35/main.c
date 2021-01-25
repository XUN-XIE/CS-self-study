/*************************************************************************
 @Author: XieXun
 @Created Time : Sat 28 Nov 10:42:57 2020
 @File Name: main.c
 @Description:
 ************************************************************************/

#include <stdio.h>

/* Determine whether arguments can be multiplied without overflow */
int tmult_ok(int x, int y) {
    int p = x*y;
    /* Either x is zero, or dividing p by x gives y */
    return !x || p/x == y;
}

int main()
{
    printf("证明题，溜了，看书中的答案更有收获\n");
}
