/*************************************************************************
 @Author: XieXun
 @Created Time : Sat 26 Dec 07:07:26 2020
 @File Name: main.c
 @Description:
 ************************************************************************/

#include <stdio.h>

int main()
{
    printf("n   P   Num PTEs\n");
    printf("12  10  4\n");
    printf("16  14  4\n");
    printf("24  21  3\n");
    printf("36  30  64\n");

    printf("Section 9.3.6 32bits space. 4KB page. 4 bytes PTE\n");
    printf("32  4KB=12  20=1M*4 = 4M\n");
}
