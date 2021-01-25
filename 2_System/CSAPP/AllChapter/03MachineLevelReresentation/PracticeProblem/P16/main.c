/*************************************************************************
 @Author: XieXun
 @Created Time : Thu  3 Dec 19:53:17 2020
 @File Name: main.c
 @Description:
 ************************************************************************/

#include <stdio.h>

void cond(short a, short *p)
{
    if (a == 0)
        goto done;
    if (*p >= a)
        goto done;
    *p = a;
done:
    return;
}
