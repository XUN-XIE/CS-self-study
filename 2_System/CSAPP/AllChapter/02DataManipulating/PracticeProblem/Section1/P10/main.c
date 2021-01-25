/*************************************************************************
 @Author: XieXun
 @Created Time : Fri 27 Nov 08:50:15 2020
 @File Name: main.c
 @Description:
 ************************************************************************/

#include <stdio.h>

void inplace_swap(int *x, int *y)
{
    *y = *x ^ *y;
    *x = *x ^ *y;
    *y = *x ^ *y;
}

int main()
{
    // crux point: *x ^ (*x ^ *y) = *y, *y ^ (*x ^ *y) = *x
    printf("\t\t*x\t*y\n"
            "Step1\t\t*x\t(*x ^ *y)\n"
            "Step2\t\t*y\t(*x ^ *y)\n"
            "Step3\t\t*y\t*x\n");

    int x = 1, y = 2;
    inplace_swap(&x, &y);
    printf("test x = 1, y = 2, we shoud get x = 2, y = 1\n"
            "result: x = %d, y = %d\n", x, y);
    return 0;
}
