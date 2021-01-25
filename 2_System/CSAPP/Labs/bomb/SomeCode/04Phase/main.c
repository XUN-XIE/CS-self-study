/*************************************************************************
 @Author: XieXun
 @Created Time : Sun  6 Dec 23:54:50 2020
 @File Name: main.c
 @Description: 用来整理 phase_4 里面的递归函数！
 ************************************************************************/

#include <stdio.h>

// first = unknown,
// second = 0
// third = 14
int func4(int first, int second = 0, int third = 14)
{
    int eax = third + second;
    int ecx = eax;
    ecx = ecx >> 31     // 这里是 logical shift ！！！  // 这里求出 second third和的 sign bit
    eax += ecx;         // 这里得到 second + third + sign_bit
    eax = eax >> 1      // 这里是 arithmetic shift！！！    // 这里得到 (second + third + sign_bit) / 2
    ecx = eax + second; // 这里求出 (second + third + sign_bit) / 2 + second
    
    if (ecx <= first)
    {
        eax = 0;
        if (ecx >= first)
            return eax;
        else
        {
            second = ecx + 1;
            eax = func4(first, second, third);
        }
    }
    else
    {
        third = ecx - 1;
        eax = func4(first, second, third);
        eax *= 2;
       return eax; 
    }
    return eax; // 我们希望得到的 eax 值是 0 ！！！
}

