/*************************************************************************
 @Author: XieXun
 @Created Time : Sun 29 Nov 10:58:00 2020
 @File Name: main.c
 @Description:
 ************************************************************************/

#include <stdio.h>

int main()
{
    // n fraction, 000...000(n bints)
    // n+1 frac,  1000...000(n+1 bits)
    // 因为 expo 可以是无限大，但是对于两者,我们要表达的是最小的正整数，所以要把小数点右面的都移位到左面
    // n + 1 fraction samllest positive integer is 1000...001(n+2 bits with n 0, last 1)**(重点，因为有 implied leading 1)**
    // 因为 n fraction 能表示 1000...0001 的两个 1 之间相距最大 n， 而 n + 1 fraction最大相距 n+1。
    // 所以，n+1 frac 能表示的最小的数 就是 1000...001(总n+2 bits)
    printf("the smallies is 2^(n+1)+1\n");
    printf("the smallest that in single-precison is 2^24+1\n");
}
