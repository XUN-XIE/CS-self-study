/*************************************************************************
 @Author: XieXun
 @Created Time : Thu  3 Dec 18:44:56 2020
 @File Name: main.c
 @Description:
 ************************************************************************/

#include <stdio.h>

int main()
{
    // Problem A
    // cmpl compare 32bits
    // setl = setnge    Less
    // %edi - %esi < 0;
    printf("Problem A, data_t = int     COMP = <\n");

    printf("Problem B, data_t = short   COMP = >=\n");

    printf("Problem C, data_t = unsigned char    COMP = <=\n");

    printf("Problem D, data_t = long or unsigned long(because setne don't distinguish signed or unsigned')    COMP = !=\n");
}
