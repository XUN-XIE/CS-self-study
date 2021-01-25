/*************************************************************************
 @Author: XieXun
 @Created Time : Wed 16 Dec 08:55:04 2020
 @File Name: main.c
 @Description:
 ************************************************************************/

#include <stdio.h>
/*
 * b = 3
 * src
 * 0    4       8       12
 * 0000 0100    1000    1100
 * set0 set0    set1    set1
 *
 * dst
 * 16   24      20      28
 * 0000 1000    0100    1100
 * set0 set1    set0    set1
 *
 * 32 bytes cache
 * 0        4       8       12
 * 00000    00100   01000   01100
 * set0     set0    set1    set1
 *
 * dst
 * 16       24      20      28
 * 10000    11000   10100   11100
 * set2     set3    set2    set3
 */ 
int main()
{
    printf("每次read和write都会直接改变对应 set。 只有在 read src[1][1]时，因为上一次的 write dst[0][1]修改的是 set0，没有修改 read src[1][0] 时的 set1， 所以 src[1][1] 是 cache hit\n");
    printf("从注释可以看出，write 的set区域 和 read 不冲突\n");
}

