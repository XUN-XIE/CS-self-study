/*************************************************************************
 @Author: XieXun
 @Created Time : Sun 29 Nov 08:51:06 2020
 @File Name: main.c
 @Description:
 ************************************************************************/

#include <stdio.h>

int main()
{
    printf("Problem A, 紧跟小数点是23位 0. 然后剩下的 [1100] 无限循环\n");
    printf("Problem B, 因为 0.1 - x 从第二十四位开始是1， 所以计算 2^(-24) + 2^(-25) + 2^(-28) + 2^(-29) +... 即可\n");
    printf("Problem C, 100 hours = 360000 seconds = 3.6E6 * 0.1 times counter, so the difference is difference in Prblem B multiply 3.6E6\n");
    printf("Problem D, 2000 m/s * difference in Problem C\n");
}
