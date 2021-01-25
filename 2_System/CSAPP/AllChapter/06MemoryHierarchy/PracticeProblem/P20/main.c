/*************************************************************************
 @Author: XieXun
 @Created Time : Wed 16 Dec 09:39:01 2020
 @File Name: main.c
 @Description:
 ************************************************************************/

#include <stdio.h>

/*
 * 一行两个，第二遍会覆盖，所以 75% hit
 *
 * 两倍大 C,需要 cold miss，还是 75%
 *
 */
int main()
{
    printf("512\n");
    printf("1/4 * 512 = 128\n");
    printf("25%%\n");
    printf("25%%\n");
}
