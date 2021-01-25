/*************************************************************************
 @Author: XieXun
 @Created Time : Wed  2 Dec 20:56:07 2020
 @File Name: main.c
 @Description:
 ************************************************************************/

#include <stdio.h>

int main()
{
    printf("Operand     Value\n");
    printf("%%rax        0x100=256\n");
    printf("0x104       0xAB\n");
    // $ represent immediate value
    printf("$0x108      0x108\n");
    // () represent get value from the address (in memory)
    printf("(%%rax)      0xFF\n");
    // Form Imm(rb)     M[R[rb]+Imm]
    printf("4(%%rax)     M[4+0x100]  M[0x104]    = 0xAB\n");
    // Form Imm(rb, ri)     M[Imm + R[rb] + R[ri]]
    printf("9(%%rax, %%rdx)   M[9 + 0x100 + 0x3]  M[0x10C]    =0x11\n");
    printf("260(%%rcx, %%rdx) M[260 + 0x1 + 0x3]  M[264] M[0x0x108]=0x13\n");
    // From Imm(,ri,s)      M[Imm + R[ri] * s]
    printf("0xFC(, %%rcx, 4)     M[0xFC + 0x1 * 4]   M[0x100]    =0xFF\n");
    // Form (rb, ri, s)     M[R[rb] + R[ri] * s]
    printf("(%%rax, %%rdx, 4)     M[0x100 + 0x3 * 4]  M[0x10C]    =0x11\n");
    
    return 0;
}
