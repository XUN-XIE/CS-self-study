/*************************************************************************
 @Author: XieXun
 @Created Time : Fri 27 Nov 17:08:14 2020
 @File Name: main.c
 @Description:
 ************************************************************************/

#include <stdio.h>

int main()
{
    //          x   binary  Unsigned
    // line 1  -1   1111        15
    // line 2  -5   1011        11
    // line 3  -6   1010        10
    // line 4  -4   1100        12
    // line 5   1   0001        1
    // line 6   8   0111        8
    
    printf("4 bits, so the conversion is 2^4 = 16\n");
    printf("         x   binary  Unsigned\n"
            "line 1  -1   1111        15 = -1 + 16\n"
            "line 2  -5   1011        11 = -5 + 16\n"
            "line 3  -6   1010        10 = -6 + 16\n"
            "line 4  -4   1100        12 = -4 + 16\n"
            "line 5   1   0001        1  = 1\n"
            "line 6   8   0111        8  = 8\n");

}
