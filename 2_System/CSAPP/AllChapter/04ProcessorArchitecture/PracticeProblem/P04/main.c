/*************************************************************************
 @Author: XieXun
 @Created Time : Mon 14 Dec 09:41:39 2020
 @File Name: main.c
 @Description:
 ************************************************************************/

#include <stdio.h>

long rproduct(long *start, long count)
{
    if (count <= 1)
        return 1;
    return *start * rproduct(start+1, count-1);
}

/*
* // %rdi = start, %rsi = count
* rproduct:
*
* irmovq $1, %rax
* irmovq $1, %r8
* irmovq $8, %r10
* subq $r8, %rsi
* jle END
* addq $r8, %rsi
* pushq %r9
* mrmovq (%rsi), %r9
* addq $r10, %rdi
* subq $1, %rsi
* call rproduct
* imulq %r9, %rax
* %popq %r9
*
* END:
*   ret
*
*
*/

int main()
{
    printf("view in the main.c file\n");
}
