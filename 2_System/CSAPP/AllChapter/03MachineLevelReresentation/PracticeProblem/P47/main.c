/*************************************************************************
 @Author: XieXun
 @Created Time : Sun  6 Dec 18:47:17 2020
 @File Name: main.c
 @Description:
 ************************************************************************/

#include <stdio.h>

int main()
{
    long local;
    printf("local is %p\n", &local);
    
    // problem A: the changeable address is from fourthth to seventh byte
    printf("problem A: 2 * 16^3\n");

    return 0;
}
