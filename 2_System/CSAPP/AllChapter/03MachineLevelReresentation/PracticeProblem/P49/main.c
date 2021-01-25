/*************************************************************************
 @Author: XieXun
 @Created Time : Sun  6 Dec 19:16:07 2020
 @File Name: main.c
 @Description:
 ************************************************************************/

#include <stdio.h>

int main()
{
    // Problem A:
    // s1 = %rsp
    // line 5: 8 * n + 22 = %rax
    // 22 = 0xff.ff16
    // line 6: %rax & 0xfff..ff0 = 
    // line 7: %rsp = s2 = s1 - %rax = 

    // n    s1      s2  p   e1  e2
    // 5    2065
    // 6    2064
}
