/*************************************************************************
 @Author: XieXun
 @Created Time : Thu  3 Dec 21:21:53 2020
 @File Name: main.c
 @Description:
 ************************************************************************/

#include <stdio.h>

short loop_while(short a, short b)
{
    short result = 0;
    while (a > b)
    {
        result = result + a * b;
        a -= 1;
    }
    return result;
}
