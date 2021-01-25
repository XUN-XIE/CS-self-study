/*************************************************************************
 @Author: XieXun
 @Created Time : Thu  7 Jan 08:44:45 2021
 @File Name: freeNULL.c
 @Description:
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>

int main()
{
    free(NULL);
    int * x = (int *)malloc(sizeof(int));
    free(x);
}

