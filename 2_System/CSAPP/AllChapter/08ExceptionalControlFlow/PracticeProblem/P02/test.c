/*************************************************************************
 @Author: XieXun
 @Created Time : Wed 23 Dec 18:47:32 2020
 @File Name: test.c
 @Description:
 ************************************************************************/

#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>

int main()
{
    int a=9;
    
    if (fork() == 0)
        printf("p1: a=%d\n", a--);
    printf("p2: a=%d\n", a++);
    exit(0);
}

