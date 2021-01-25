/*************************************************************************
 @Author: XieXun
 @Created Time : Thu  7 Jan 08:07:43 2021
 @File Name: printAddress.c
 @Description:
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("location of code : %p\n", (void *) main);
    void * heap = malloc(1);
    printf("location of heap : %p\n", heap);
    free(heap);
    int x = 3;
    printf("location of stack: %p\n", (void *) &x);

    return x;
}
