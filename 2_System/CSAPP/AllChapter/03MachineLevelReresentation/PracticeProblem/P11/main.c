/*************************************************************************
 @Author: XieXun
 @Created Time : Wed  2 Dec 20:56:07 2020
 @File Name: main.c
 @Description:
 ************************************************************************/

#include <stdio.h>

int main()
{
    printf("makes the register value in %%rcx to be 0\n");
    printf("movq $0, %%rcx\n");
    
    printf("\n\n\n 不知道这个指令的字节是怎么计算的\n");
    printf("From book answer: the version with xorq requires only 3 bytes, while the version with movq requires 7.\n"); 
    printf("Other ways to set %%rcx to zero rely on the property that any instruction that updates the lower 4 bytes will cause the high-order bytes to be set to zero. Thus, we could use either xorl %%ecx,%%ecx (2 bytes) or movl $0,%%ecx (5 bytes).\n");
}
