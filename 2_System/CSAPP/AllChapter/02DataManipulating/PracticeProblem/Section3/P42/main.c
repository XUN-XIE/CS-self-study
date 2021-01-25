/*************************************************************************
 @Author: XieXun
 @Created Time : Sat 28 Nov 12:54:39 2020
 @File Name: main.c
 @Description:
 ************************************************************************/

#include <stdio.h>

// 这题看了答案，巧妙的使用了 bit mask！
int div16(int num)
{
    int mask = (num >> 31) & 0xf;
    return (num + mask) >> 4;
}

int main()
{
    printf("17 / 16 = %d\n", div16(17));
    printf("-17 / 16 = %d\n", div16(-17));

    return 0;
}
