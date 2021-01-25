/*************************************************************************
 @Author: XieXun
 @Created Time : Wed 23 Dec 18:44:11 2020
 @File Name: main.c
 @Description:
 ************************************************************************/

#include <stdio.h>

int main()
{
    printf("Child process:\n");
    printf("p1: a=9\n");
    printf("p2: a=8\n");

    printf("\nParent process:\n");
    printf("p2: a=9\n");
}
