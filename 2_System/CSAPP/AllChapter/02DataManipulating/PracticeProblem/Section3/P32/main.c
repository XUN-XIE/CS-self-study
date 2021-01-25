/*************************************************************************
 @Author: XieXun
 @Created Time : Fri 27 Nov 22:55:02 2020
 @File Name: main.c
 @Description:
 ************************************************************************/

#include <stdio.h>

/* Determine whether arguments can be added without overflow */
int tadd_ok(int x, int y)
{
    if ( x > 0 && y > 0)
        return x+y > x ? 1 : 0;
    if ( x < 0 && y < 0)
        return x+y < x ? 1 : 0;
    return 1;
}

/* Determine whether arguments can be subtracted without overflow */
/* WARNING: This code is buggy. */
int tsub_ok(int x, int y) {
    return tadd_ok(x, -y);
}

int main()
{
   // 找到一个情况 明明发生overflow 却成功的例子
   // 或者 没有发生 overflow，却失败的例子
   // x = INT_MAX, y = - INT_MAX
   // tadd_ok(INT_MAX, INT_MAX) = 0, 但其实没有 overflow！
    printf("for example: x = INT_MAX, y = - INT_MAX\n");
    printf("then, in tsub_ok, the call to tadd_ok(INT_MAX, INTMAX)\n");
    printf("this will return 0, but actually this is not an overflow!\n");

    return 0;
}
