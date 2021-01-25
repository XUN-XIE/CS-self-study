/*************************************************************************
 @Author: XieXun
 @Created Time : Mon  7 Dec 00:37:56 2020
 @File Name: main.c
 @Description: 主要写出 内部循环的逻辑
 ************************************************************************/

#include <stdio.h>

int main()
{
    char * string = "abcdef" // 必须长度为6
    int eax = 0;
    
    int notEqual = 1;
    while (eax != 6)
    {
        int ecx = string[eax];
        // (%rsp) = ecx
        string[0] = ecx;
        int rdx = string[0];
        rdx = rdx & 15; // 0x?? & 0x0f
        // 取出下面这段字符串中 对应 rdx 位置的字符
        // maduiersnfotvbylSo you think you can stop t    he bomb with ctrl-c, do you?
        //      *** *    **                                *              *   
        // f:       9
        // l:             15                                              63 
        // y:            14
        // e:   5                                          48
        // r:    6
        // s:     7
        // 逻辑就是 在这一段字符串中 依次取出 flyers
        //
        //  ? & 15 = 5 - 15
        //  64 & 15 = 0
        //  9 --> 73 --> I
        //  15 --> 79 --> O
        //  14 --> 78 --> N
        //  5 --> 69 --> E
        //  6 --> 70 --> F
        //  7 --> 71 --> G
        rdx = *(0x4024b0 + rdx);
        *(string + eax + 16) = rdx;
        eax += 1;
    }

    *(string + 22) = 0;
    int esi = 0x40245e;
    // 
    //最后比较的是 %rsp + 16 到 %rsp + 22 之间的字符串
    //和 0x40245e 的 "flyers" 对比，不能相等即可
}
