/*************************************************************************
 @Author: XieXun
 @Created Time : Sat 26 Dec 10:32:52 2020
 @File Name: main.c
 @Description:
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int * test = (int *) malloc(sizeof(int));
    *test = 1;
    printf("%d %x\n", *test, test);
    free(test);
    printf("%d %x\n", *test, test);

}

