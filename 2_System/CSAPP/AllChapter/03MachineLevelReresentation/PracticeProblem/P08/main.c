/*************************************************************************
 @Author: XieXun
 @Created Time : Wed  2 Dec 20:56:07 2020
 @File Name: main.c
 @Description:
 ************************************************************************/

#include <stdio.h>

int main()
{
    printf("Instruction         Destination Value\n");
    printf("addq %%rcx,(%%rax)    0x100       0x100\n");
    printf("subq %%rdx,8(%%rax)   0x108       0xA8\n");
    printf("imulq $16,(%%rax,%%rdx,8)     0x118   0x110\n");
    printf("incq 16(%%rax)       0x110       0x14\n");
    printf("decq %%rcx           %%rcx        0x0\n");
    printf("subq %%rdx,%%rax      %%rax        0xFD\n");
}
