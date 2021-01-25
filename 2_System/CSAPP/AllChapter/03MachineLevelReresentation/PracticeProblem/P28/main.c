/*************************************************************************
 @Author: XieXun
 @Created Time : Thu  3 Dec 21:44:11 2020
 @File Name: main.c
 @Description:
 ************************************************************************/

#include <stdio.h>

short test_two(unsigned short x)
{
    short val = 0;
    short i;
    for ( i = 64; i != 0; i--)
    {
        val = (val << 1) | (x & 0x1);
        x = x >> 1;
    }
    return val;
}
