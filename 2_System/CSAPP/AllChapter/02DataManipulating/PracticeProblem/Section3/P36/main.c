/*************************************************************************
 @Author: XieXun
 @Created Time : Sat 28 Nov 10:54:24 2020
 @File Name: main.c
 @Description:
 ************************************************************************/

#include <stdio.h>
#include <limits.h>
int tmult_ok(int x, int y)
{
    int64_t high_preci  = (int64_t)x * (int64_t)y;
    return high_preci == (int) high_preci;
}

int main()
{
    int x = INT_MAX / 2, y = INT_MAX / 2 + 10;
    printf("test case 1: result shoud be 0, result is %d\n", tmult_ok(x , y));

    x = - INT_MAX / 2, y = - INT_MAX / 2 - 10;
    printf("test case 2: result shoud be 0, result is %d\n", tmult_ok(x , y));

    x = - INT_MAX / 2, y = 2;
    printf("test case 3: result shoud be 1, result is %d\n", tmult_ok(x , y));

    x = INT_MAX / 2, y = - 2;
    printf("test case 4: result shoud be 1, result is %d\n", tmult_ok(x , y));
    
    return 0;
}
