/*************************************************************************
 @Author: XieXun
 @Created Time : Thu  3 Dec 20:15:26 2020
 @File Name: main.c
 @Description:
 ************************************************************************/

#include <stdio.h>

long lt_cnt = 0;
long ge_cnt = 0;

long absdiff_se(long x, long y)
{
    long result;
    if (x < y)
        goto True;
    ge_cnt++;
    result = x - y;
    goto done;
True:
    lt_cnt++;
    result = y - x;
    goto done;
done:
    return result;
}
