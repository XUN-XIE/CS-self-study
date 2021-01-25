/*************************************************************************
 @Author: XieXun
 @Created Time : Sat 28 Nov 10:35:09 2020
 @File Name: main.c
 @Description:
 ************************************************************************/

#include <stdio.h>

int main()
{
    printf("Mode            x           y           x*y     Truncated x* y\n");
    printf("Unsigned    4   100     5   101     20  010100  4   100\n");
    printf("Two'sC      -4  100     -3  101     12  001100  -4  100\n");
    printf("Unsigned    2   010     7   111     14  001110  6   110\n");
    printf("Two'sC      2   010     -1  111     -2  111110  -2  110\n");
    printf("Unsigned    6   110     6   110     36  100100  4   100\n");
    printf("Two'sC      -2  110     -2  110     4   000100  -4  100\n");

    return 0;
}
