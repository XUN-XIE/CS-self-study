/*************************************************************************
 @Author: XieXun
 @Created Time : Thu  3 Dec 20:45:15 2020
 @File Name: main.c
 @Description:
 ************************************************************************/

#include <stdio.h>

short arith(short x)
{
    return (x > 0 ? x : x + 15) / 16;
}

int main()
{
    printf("回忆第二章的 除法， 如果是负数需要加 bias， 正数则不需要，所以存在了 comvns 用来判断正负，决定是否加 bias\n");
}
