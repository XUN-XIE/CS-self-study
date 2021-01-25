/*************************************************************************
 @Author: XieXun
 @Created Time : Mon 14 Dec 10:38:21 2020
 @File Name: main.c
 @Description:
 ************************************************************************/

#include <stdio.h>

int main()
{
    printf("icode: ifun <-- M1[0x016] = 3:0\n");
    printf("rA: rB      <-- F: 4\n");
    printf("valC        <-- 128\n");
    printf("valP        <-- 0x016+0xa = 0x020\n");
    printf("\n\n");
    printf("valE        <-- 0 + valC = 128\n");
    printf("\n\n");
    printf("R[rB] <-- valE      %rsp = 128\n");
    printf("PC = 0x020\n");
}
