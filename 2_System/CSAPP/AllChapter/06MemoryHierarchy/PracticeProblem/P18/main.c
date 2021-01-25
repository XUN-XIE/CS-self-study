/*************************************************************************
 @Author: XieXun
 @Created Time : Wed 16 Dec 09:14:24 2020
 @File Name: main.c
 @Description:
 ************************************************************************/

#include <stdio.h>

/*
 * B = 16 --> b = 4
 * C = 1024 bytes --> m = 10
 * index --> s = 6 --> Sets = 64
 *
 * 16 / 8 = 2, one block store 2 elements
 */
int main()
{
    printf("Problem A: number of read is 16 * 16 * 2 = 512\n");
    printf("Problem B: 256 / 2 * 2 = 256\n");
    printf("Problem C: 256 / 512 = 50%%\n");
}
