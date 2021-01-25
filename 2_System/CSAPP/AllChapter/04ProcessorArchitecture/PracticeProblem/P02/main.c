/*************************************************************************
 @Author: XieXun
 @Created Time : Thu 10 Dec 10:57:54 2020
 @File Name: main.c
 @Description:
 ************************************************************************/

#include <stdio.h>

int main()
{
    // A: 
    // 30f3 --> irmovq
    // 3 --> %rbx
    // fc ff ff ff ff ff ff ff 
    //
    //
    // 40 63 --> rmmovq
    // 6 --> %rsi
    // 3 --> %rbx
    // 00 08 00 00 00 00 00 00
    printf("Problem A:\n");
    printf("0x100:  irmovq $ -4, %%rbx\n");
    printf("0x10a:  rmmovq %%rsi, 0x800(%%rbx)\n\n");

    // B:
    // a06f
    // a0 --> pushq
    // 6 --> %rsi
    // 80 
    // 80 --> call
    // 0c 02 00 00 00 00 00 00 
    // 
    // 00 --> halt
    // 
    // 30 --> irmovq
    // 3 --> %rbx
    // 0a 00 00 00 00 00 00 00
    printf("Probelm B\n");
    printf("0x200:  pushq %%rsi\n");
    printf("0x202:  call 0x20c\n");
    printf("0x20b:  halt\n");
    printf("0x20c:  irmovq $10, %%rbx\n\n");

    // C:
    // 5054 --> mrmovq %rbp, %rsp
    // 07 00 00 00 00 00 00 00 
    //
    // 10 --> nop
    // f0 --> 
    // b01f --> popq %rcx
    printf("Probelm C\n");
    printf("0x300:  mrmovq 7(%%rbp), %%rsp\n");
    printf("0x30a:  nop\n");
    printf("0x30b:  f0 !!!! invalid instruction encoding!\n");
    printf("0x30c:  popq %%rcx\n\n");

    // D:
    // 6113 --> subq %rcx, %rbx
    // 73 00 04 00 00 00 00 00 00 --> je 0x400
    //  
    // 00 --> halt
    printf("Probelm D\n");
    printf("0x400:  subq %%rcx, %%rbx\n");
    printf("0x402:  je 0x400\n");
    printf("0x40c:  halt\n\n");

    // E:
    // 6362 --> xorq %rsi, %rdx
    // a0f0 --> pushq !!!!invalid encoding
    printf("Probelm E\n");
    printf("0x500:  xorq %%rsi, %%rdx\n");
    printf("0x502:  a0f0, invalid encoding!\n");
    //
}
