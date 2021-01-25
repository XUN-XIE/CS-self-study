/*************************************************************************
 @Author: XieXun
 @Created Time : Wed  2 Dec 20:56:07 2020
 @File Name: main.c
 @Description:
 ************************************************************************/

#include <stdio.h>

int main()
{   
    //  movb $0xF, (%ebx)       immediate --> memory
    //       8bits  64bits
    printf("movb $0xF, (%%ebx). %%ebx is 32 bits, so it cannot be used to be as address register! we must use 64 bits address register to reference memory\n\n");
    //  movl %rax, (%rsp)       register --> memory
    //       64bits 64bits
    printf("movl %%rax, (%%rsp). the bits is too small, just 32bits which cannot move the 64bits to 64bits\n\n");
    //  movw (%rax),4(%rsp)     memory --> memory
    printf("movw (%%rax),4(%%rsp).    it cannot move from memory to memory!\n\n");
    //  movb %al,%sl            register --> register
    //       8bits 
    printf("movb %%al,%%sl.   there is not a register named %%sl");
    //  movq %rax,$0x123        register --> immediate
    printf("movq %%rax,$0x123.       it cannot move from register to immediate value\n\n");
    //  movl %eax,%rdx          register --> register
    //       32bits 64bits
    printf("movl %%eax, %%rdx. %%eax is 32bits, whereas %%rdx is 64 bits. we cannot use mov class to move between different size. there are movs, movz to do this\n\n");
    //  movb %si, 8(%rbp)       register --> memory
    //       16bits 64bits
    printf("movb %%si, 8(%%rbp). the bits is too small, just 8bits which cannot move the 16bits to 64bits\n\n");
}
