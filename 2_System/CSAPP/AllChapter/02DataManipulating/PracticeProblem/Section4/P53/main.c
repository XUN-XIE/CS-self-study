/*************************************************************************
 @Author: XieXun
 @Created Time : Sun 29 Nov 12:48:31 2020
 @File Name: main.c
 @Description:
 ************************************************************************/

#include <stdio.h>

// bias is 2^11
#define POS_INFINITY    0111...111(expo field all 1, eleven 1s)000...000(fracation filed, 52 0s)
#define NEG_INFINITY    1111...111(expo field all 1, eleven 1s)000...000(fracation filed, 52 0s)
#define NEG_ZERO        1000...000(63 0s)

int main()
{
    printf("参考答案，INIFINITY 直接设置比 题目中给出的估计值，更大即可，比如答案中的 1E400\n");
    printf("值得注意的是 答案中 NEG_ZERO = -1 / POS_INFINIT\nY");
    printf("POS_INFINITY = 2^12 - 2^11 + 1\n");
    printf("NEG_INFINITY = 0 - 2^11 - 1\n");
    printf("WRONG ANSWER: NEG_ZEO = 0\n");
}

