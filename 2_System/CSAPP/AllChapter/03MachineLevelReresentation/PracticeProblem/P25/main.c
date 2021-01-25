/*************************************************************************
 @Author: XieXun
 @Created Time : Thu  3 Dec 21:29:37 2020
 @File Name: main.c
 @Description:
 ************************************************************************/

#include <stdio.h>

long loop_while2(long a, long b)
{
    long result = b;
    while (b > 0)
    {
        result = a * result;
        b = b - a;
    }
    return result;
}
