/*************************************************************************
 @Author: XieXun
 @Created Time : Fri 27 Nov 21:33:44 2020
 @File Name: main.c
 @Description:
 ************************************************************************/

#include <stdio.h>

/* Determine whether arguments can be added without overflow */
int uadd_ok(unsigned x, unsigned y)
{
    return (x + y) > x ? 1 : 0;
}

int main()
{
    // MAX_INT = 2147483647
    // test case 1, x = 2147483647, y = 10
    int x = 2147483647, y = 10;
    printf("first test result should be 1, the reuslt is %d\n", uadd_ok(x, y));
    
    // test case 2, x = 2147483647, y = 2147483649
    x = 2147483647, y = 2147483649;
    printf("second test result should be 0, the reuslt is %d\n", uadd_ok(x, y));

}
