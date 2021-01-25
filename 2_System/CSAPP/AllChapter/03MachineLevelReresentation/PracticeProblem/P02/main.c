/*************************************************************************
 @Author: XieXun
 @Created Time : Wed  2 Dec 20:56:07 2020
 @File Name: main.c
 @Description:
 ************************************************************************/

#include <stdio.h>

int main()
{   
    // One important feature is that memory references in x86-64 are always given with quad word registers, such as %rax, even if the operand is a byte, single word, or double word.
    // second point is to find Figure 3.2 to find out the bits of different register references

    // %eax     (%rsp)  register --> memory
    // 32 bits  64 bits
    printf("movl    %%eax     (%%rsp)\n");
    // (%rax)   %dx     memory --> register
    // 64bits   16bits
    printf("movw    (%%rax)   %%dx\n");
    // $0xFF    %bl     Immediate --> register
    // 8bits    8bits
    printf("movb    $0xFF    %%bl\n");
    // (%rsp, %rdx, 4)  %dl     memory --> register
    // 64bits           8bits
    printf("movb    (%%rsp, %%rdx, 4)  %%dl\n");
    // (%rdx)   %rax    memory --> register
    // 64bits   64bits
    printf("movq    (%%rdx)   %%rax\n");
    // %dx      (%rax)  register --> memory
    // 16bits   64bits
    printf("movw    %%dx      (%%rax)\n");

    return 0;
}
