/*************************************************************************
 @Author: XieXun
 @Created Time : Fri 27 Nov 08:05:36 2020
 @File Name: main.c
 @Description:
 ************************************************************************/

#include <stdio.h>

int main()
{
    // a    0100 1110
    // b    1110 0001
    // ~a   1011 0001
    // ~b   0001 1110
    // a&b  0100 0000
    // a|b  1110 1111
    // a^b  1010 1111
    printf("~a\t= 1011 0001\n"
            "~b\t= 0001 1110\n"
            "a&b\t= 0100 0000\n"
            "a|b\t= 1110 1111\n"
            "a^b\t= 1010 1111\n");
}