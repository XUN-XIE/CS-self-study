/*************************************************************************
 @Author: XieXun
 @Created Time : Fri 27 Nov 19:31:59 2020
 @File Name: main.c
 @Description:
 ************************************************************************/

#include <stdio.h>

/* WARNING: This is buggy code */
float sum_elements(float a[], unsigned length) {
    int i;
    float result = 0;
    
    for (i = 0; i <= length-1; i++)
        result += a[i];
    return result;
}

// When run with argument length equal to 0, this code should return 0.0. Instead, it encounters a memory error.

int main()
{
    printf("因为 length 是 unsigned 数据， 在循环里计算时，会先减去1，导致underflow，使得循环内条件判断位 i <= INT_MAN, 然后 数组a 不可能有这么大的空间，导致内存错误，segmentation fault\n"); 
}
