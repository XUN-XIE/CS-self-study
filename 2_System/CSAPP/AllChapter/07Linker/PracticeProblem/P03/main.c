/*************************************************************************
 @Author: XieXun
 @Created Time : Wed 23 Dec 09:11:13 2020
 @File Name: main.c
 @Description:
 ************************************************************************/

#include <stdio.h>

int main()
{
    printf("Problem A:\n");
    printf("gcc p.c libx.a\n");

    printf("Problem B:\n");
    printf("gcc p.c libx.c liby.c\n");

    printf("Problem C:\n");
    printf("gcc p.c libx.a liby.a libx.a\n");
}
