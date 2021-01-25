/*************************************************************************
 @Author: XieXun
 @Created Time : Fri 27 Nov 22:40:40 2020
 @File Name: main.c
 @Description:
 ************************************************************************/

#include <stdio.h>
#include <limits.h>
/* Determine whether arguments can be added without overflow */
int tadd_ok(int x, int y)
{
    if ( x > 0 && y > 0)
        return x+y > x ? 1 : 0;
    if ( x < 0 && y < 0)
        return x+y < x ? 1 : 0;
    return 1;
}

int main()
{
    // test case 1 x = y = INT_MAX
    int x = INT_MAX;
    int y = INT_MAX;
    printf("test csae 1 should be 0. result is %d\n", tadd_ok(x, y));
    
    // test csae 2 x = 10, y = 10
    x = y = 10;
    printf("test case 2 should be 1, result is %d\n", tadd_ok(x, y));

    // test csae 3  x = y = - INT_MAX
    x = y = - INT_MAX;
    printf("test csae 3 should be 0, result is %d\n", tadd_ok(x, y));

    // test case 4, x = y = -10;
    x = y = -10;
    printf("test case 4 should be 1, result is %d\n", tadd_ok(x, y));
    
    // test case 5, x = 10, y = -10
    x = 10;
    y = -10;
    printf("test case 5 should be 1, result is %d\n", tadd_ok(x, y));

    return 0;
}
