/*************************************************************************
 @Author: XieXun
 @Created Time : Sat 26 Dec 09:54:58 2020
 @File Name: main.c
 @Description:
 ************************************************************************/

#include <stdio.h>

int main()
{
    // Virtual address = 0x03d7
    //  0000 0011 1101 0111
    printf("Problem A:\n");
    printf("00 0011 1101 0111\n");
    printf("Problem B:\n");
    printf("VPN = 0011 11 = 0x0f\n");
    printf("TLB index = 11 = 0x3\n");
    printf("TLB tag = 0011 = 0x3\n");
    printf("TLB hit = Y\n");
    printf("Page fault = F\n");
    // PPN = 2D, valid = 1
    printf("PPN = 0xD\n");

    printf("\n\n");
    printf("Problem C\n");
    printf("0011 0101 0111\n");
    printf("Problem D\n");
    printf("Byte Offset = 3\n");
    printf("Cache Index = 5\n");
    printf("Cache tag = 0x0D\n");
    printf("Cache hit = Y\n");
    printf("Cache byte returned = 0x1D\n");
}
