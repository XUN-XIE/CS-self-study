/*************************************************************************
 @Author: XieXun
 @Created Time : Sun  6 Dec 17:59:21 2020
 @File Name: main.c
 @Description:
 ************************************************************************/

#include <stdio.h>

int main()
{
    printf("Problem A: push %rbx, 8byptes. one row next to return adrress.\n");
    printf("Then, sub %rsp by 10. means it allocate 10 byte space to the call of gets!\n");

    // 这个图中为什噩梦在 stack 扩充10的情况下，扩充出 2 行，不知道为什么。
    // 按道理说，应该在 %rbx 储存后，只扩充 10 个字节，但是两行是 16 字节！
}
