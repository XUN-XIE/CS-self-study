/*************************************************************************
 @Author: XieXun
 @Created Time : Fri  4 Dec 19:36:54 2020
 @File Name: main.c
 @Description:
 ************************************************************************/

#include <stdio.h>

void while_(void)
{
    long sum = 0;
    long i = 0;
    while (i < 10)
    {
        if (i & 1)
            continue;
        sum += i;
        i++;
    }
    return;
}

void goto_(void)
{
    long sum = 0;
    long i = 0;
    while (i < 10)
    {
        if (i < 10)
            goto update;
        sum += i;
update:
        i++;
    }
}
