/*************************************************************************
 @Author: XieXun
 @Created Time : Sat 28 Nov 13:03:43 2020
 @File Name: main.c
 @Description:
 ************************************************************************/

#include <stdio.h>

#define M  31    /* Mystery number 1 */
#define N   8    /* Mystery number 2 */
int arith(int x, int y) {
    int result = 0;
    result = x*M + y/N; /* M and N are mystery numbers. */
    return result;
}

/* Translation of assembly code for arith */
int optarith(int x, int y) {
    int t = x;
    // x << 5 = 100000
    x <<= 5;
    // x -> 011111
    x -= t;
    // bias 7 = 0111
    // y >> 3 消除 bias
    if (y < 0) y += 7;
    y >>= 3;  /* Arithmetic shift */
    return x+y;
}


int main()
{
    printf("M = 31, N = 8\n");
    printf("x << 5 - x 等同于 乘以 x * 32 - x = 31 * x\n");
    printf("y 进行了条件判断，可以知道这是除法里为了 bias！所以 y >> 3 所以是 y /= 8\n");

    return 0;
}
