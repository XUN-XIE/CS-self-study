/*************************************************************************
 @Author: XieXun
 @Created Time : Thu 26 Nov 23:17:56 2020
 @File Name: main.c
 @Description:
 ************************************************************************/

#include <stdio.h>

int main()
{
    int a = 0x12345678;
    unsigned char * ap = (unsigned char *)&a;
    for (int i = 0; i < 4; i++)
        printf("%.2x ", ap[i]);
    printf("\n");
    printf("A little = 78, big = 12\n");
    printf("B little = 78 56, big = 12 34\n");
    printf("C little = 78 56 34, big = 12 34 56\n");

    return 0;
}
