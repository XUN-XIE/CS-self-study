/*************************************************************************
 @Author: XieXun
 @Created Time : Mon 14 Dec 10:47:42 2020
 @File Name: main.c
 @Description:
 ************************************************************************/

#include <stdio.h>

int main()
{
    printf("icode: ifun <-- M1[0x02c]\n");
    printf("rA: rB      <-- 0: F\n");
    printf("valP        <-- 0x02c + 2 = 0x02e\n");
    printf("\n\n");
    printf("valA        <-- 120\n");
    printf("valB        <-- 120\n");
    printf("valE        <-- 120 + 8 = 128\n");
    printf("valM        <-- M8[120] = 9\n");
    printf("R[%%rsp]     <-- valE        %%rsp = 120\n");
    printf("R[rA]       <-- valM        %%rax = M8[120] = 9\n");
    printf("PC = 0x02e\n");
}
