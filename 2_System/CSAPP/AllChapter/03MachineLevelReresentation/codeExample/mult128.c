/*************************************************************************
 @Author: XieXun
 @Created Time : Thu  3 Dec 11:14:57 2020
 @File Name: mult128.c
 @Description:
 ************************************************************************/

#include <stdio.h>
#include <inttypes.h>

typedef unsigned __int128 uint128_t;

void stroe_uprod(uint128_t *dest, uint64_t x, uint64_t y)
{
    *dest = x * (uint128_t) y;
}

