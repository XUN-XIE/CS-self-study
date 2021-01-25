/*************************************************************************
 @Author: XieXun
 @Created Time : Fri 27 Nov 19:36:04 2020
 @File Name: main.c
 @Description:
 ************************************************************************/

#include <stdio.h>
#include <string.h>
/* Determine whether string s is longer than string t */
/* WARNING: This function is buggy */
int strlonger(char *s, char *t) {
    return strlen(s) - strlen(t) > 0;
}

// data type size_t is defined (via typedef) in header file stdio.h to be unsigned.

int main()
{
    
    printf("Problem A: 当 string s 的长度比 t 的长度小时，返回的是一个非常大的数， 所以必定大于 0，最后返回 1\n");
    printf("Problem B: 因为当 s 的长度 比 t 小时， strlen(s) - strlen(t) 发生underflow，导致结果很大，所以返回还是 1\n");
    printf("Problem C: 强制转换为 signed 类型进行比较，因为一般的字符串长度也不可能大到 大于 2^16\n");
}
