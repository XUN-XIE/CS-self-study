/*************************************************************************
 @Author: XieXun
 @Created Time : Mon 14 Dec 09:41:39 2020
 @File Name: main.c
 @Description:
 ************************************************************************/

#include <stdio.h>

/*
sum:
  irmovq $8,%r8
  irmovq $1,%r9
  xorq %rax,%rax
  andq %rsi,%rsi
  jmp     test
loop:
  mrmovq (%rdi),%r10
  andq %r10, %r10
  jl POS
  jmp THEN
POS:
  neg %r10
THEN:
  addq %r10,%rax
  addq %r8,%rdi
  subq %r9,%rsi
test: 
  jne loop 
  ret
 *
 *
*/
/*
 *
 *
 *
*/
int main()
{
    printf("view the file\n");
}
