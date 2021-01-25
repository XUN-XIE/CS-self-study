/*************************************************************************
 @Author: XieXun
 @Created Time : Wed  2 Dec 20:56:07 2020
 @File Name: main.c
 @Description:
 ************************************************************************/

#include <stdio.h>

// src_t *sp;
// dest_t *dp;

// *dp = (dest_t) *sp;

// sp --> %rdi
// dp --> %rsi
//
// options: %rax, %eax, %ax, %al
//          64    32    16   8  bits

int main()
{
    // char --> int     1btye --> 4bytes
    // movsbl (%rdi), %eax  
    // movl %eax, (%rsi)
    printf("char --> int     1btye --> 4bytes   movsbl (%%rdi), %%eax     movl %%eax, (%%rsi)\n");

    // char --> unsigned (int)  1byte --> 4byte
    // movsbl 
    printf("same as above, because the source type is same, so we don't need to change movsbl to movzbl\n");

    // unsigned char --> long   1byte --> 8byte
    // movzbq   (%rdi), %rax
    // movq     %rax, (%rsi)
    printf("unsigned char --> long  movzbq   (%%rdi), %%rax     movq     %%rax, (%%rsi)\n");

    // int --> char     4bytes --> 1bytes
    
    // 读取的时候，只考虑左面的类型，因此读取4字节，movl
    // movl (%%rdi), %%eax
    
    //  从这题可以看出，其实只有十六个寄存器，只不过每一行对应的是不同位的截取
    // movb (%%al), (%%rsi)
    printf("int --> char    movl (%%rdi), %%eax     movb (%%al), (%%rsi)\n");

    // unsigned --> unsigned char   4bytes --> 1bytes
    // movl (%%rdi), %%eax
    // movb %%al,    (%%rsi)
    printf("unsigned --> unsigned char      movl (%%rdi), %%eax     movb %%al,    (%%rsi)\n");

    // char --> short   1byte --> 2byte
    // movsbw   (%%rdi), %%ax
    // movw     %%ax, (%%rsi)
    printf("char --> short  movsbw   (%%rdi), %%ax  movw     %%ax, (%%rsi)\n");
}
