/*************************************************************************
 @Author: XieXun
 @Created Time : Fri 27 Nov 08:35:37 2020
 @File Name: main.c
 @Description:
 ************************************************************************/

#include <stdio.h>

int main()
{
    // Problem A
    printf("Problem A Answer is:\n"
            "Black to White\n"
            "Blue to Yellow\n"
            "Green to Magenta\n"
            "Cyan to Red\n"
            "And the reverse of all above is also the remaining answers\n");
    
    // Problem B
    // line 1   001 | 010 = 011 = Cyan
    // line 2   110 & 011 = 010 = Green
    // line 3   100 ^ 101 = 001 = Blue
    printf("\nProblem B Answer is:\n"
            "line 1   001 | 010 = 011 = Cyan\n"
            "line 2   110 & 011 = 111 = Green\n"
            "line 3   100 ^ 101 = 001 = Blue\n");
    return 0;
}
