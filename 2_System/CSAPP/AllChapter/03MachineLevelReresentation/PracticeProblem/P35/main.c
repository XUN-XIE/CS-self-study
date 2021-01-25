/*************************************************************************
 @Author: XieXun
 @Created Time : Sat  5 Dec 08:56:03 2020
 @File Name: main.c
 @Description:
 ************************************************************************/

#include <stdio.h>

long rfun(unsigned long x)
{
    if (x == 0)
        return 0;
    unsigned long nx = x >> 2;
    long rv = rfun(nx);
    return rv + x;
}
