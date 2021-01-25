/*************************************************************************
 @Author: XieXun
 @Created Time : Thu  3 Dec 11:07:38 2020
 @File Name: mian.c
 @Description:
 ************************************************************************/

#include <stdio.h>

int main()
{
    printf("the changes happened in:\n");
    printf("line 4: movl    $0, %%rdx       to set upper 8 bytes of dividned to 0\n");
    printf("line 5: divq    %%rsi           change from idivq to divq\n");
}
