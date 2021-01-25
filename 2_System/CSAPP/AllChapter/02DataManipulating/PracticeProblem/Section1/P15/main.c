/*************************************************************************
 @Author: XieXun
 @Created Time : Fri 27 Nov 10:13:54 2020
 @File Name: main.c
 @Description:
 ************************************************************************/

#include <stdio.h>

int equalTo(int x, int y)
{
    return !(x ^ y);
}

int main()
{
    // test case 1 : x = 2, y = 2
    printf("x = 2, y = 2, bool = %d\n", equalTo(2, 2));

    // test case 2 : x = 3, y = 2
    printf("x = 3, y = 2, bool = %d\n", equalTo(3, 2));
}
