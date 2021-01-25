/*************************************************************************
 @Author: XieXun
 @Created Time : Thu 10 Dec 10:36:07 2020
 @File Name: main.c
 @Description:
 ************************************************************************/

#include <stdio.h>

int main()
{
    // start from 0x100?
    // irmovq $15, %rbx
    // irmovq --> 3 0 F Rb
    // 15 --> 00 00 00 00 00 00 00 0f -> 0f 00 00 00 00 00 00 00
    // Rb --> %rbx --> 3
    printf("0x100:  30F3 0f 00 00 00 00 00 00 00\n");
    // 10 bytes, address become 0x10a
    // rrmovq --> 2 0 Ra Rb
    // %rbx --> Ra --> 3
    // %rcx --> Rb --> 1
    //
    printf("0x10a:   20 31\n");
    // 2 bytes, address become 0x10c
    printf("0x10c\n");
    // 0 bytes
    // rmmovq --> 40 Ra Rb
    // %rcx --> 1
    // %rbx --> 3
    // -3   --> ff ff ff ff ff ff ff fd
    printf("0x10c:  40 13 fd ff ff ff ff ff ff ff\n");
    // 10 bytes, address become 0x116
    // addq --> 60
    // %rbx --> 3
    // %rcx --> 1
    printf("0x116:  60 31\n");
    // 2 bytes, address become 0x118
    // jmp --> 70
    // loop --> 0x10c --> 00 00 00 00 00 00 01 0c
    //
    printf("0x118:  70 0c 01 00 00 00 00 00 00\n");

}
