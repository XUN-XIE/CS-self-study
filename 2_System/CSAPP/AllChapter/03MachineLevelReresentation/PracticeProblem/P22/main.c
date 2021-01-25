/*************************************************************************
 @Author: XieXun
 @Created Time : Fri  4 Dec 18:50:10 2020
 @File Name: main.c
 @Description:
 ************************************************************************/

#include <stdio.h>
#include <limits.h>
int main()
{
    int32_t result = 1;
    int32_t count = 1;
    do {
        result *= count++;
    } while (count <= 14);
    printf("result = %d,    count = %d\n", result, count);
    printf("INT_MAX= %d\n", INT_MAX);
}
