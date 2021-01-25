/*************************************************************************
 @Author: XieXun
 @Created Time : Mon 14 Dec 10:04:34 2020
 @File Name: main.c
 @Description:
 ************************************************************************/

#include <stdio.h>

int main()
{
    printf("the result is zero, which means the value of %%rsp pushed onto stack is the old version. So, if we push %%rsp, it will first push %%rsp, then increment %%rsp by 8\n");
}
