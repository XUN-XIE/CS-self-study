/*************************************************************************
 @Author: XieXun
 @Created Time : Mon 14 Dec 10:58:17 2020
 @File Name: main.c
 @Description:
 ************************************************************************/

#include <stdio.h>

int main()
{
    printf("icode: ifun <-- M1[0x037] = 8: 0\n");
    printf("valC        <-- M8[0x038] = 0x41\n");
    printf("valP        <- 0x037 + 9 = 0x040\n");
    printf("valB        <-- R[%%rsp] = 128\n");
    printf("valE        <-- valB + (-8) = 120\n");
    printf("M8[valE]    <-- valP = 0x040\n");
    printf("R[%%rsp]    <-- valE = 120\n");
    printf("PC = valC = 0x41\n");
}
