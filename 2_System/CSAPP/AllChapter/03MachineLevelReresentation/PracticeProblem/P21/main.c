/*************************************************************************
 @Author: XieXun
 @Created Time : Thu  3 Dec 20:55:49 2020
 @File Name: main.c
 @Description:
 ************************************************************************/

#include <stdio.h>

// short test(short x, short y)
// x in %rdi, y in %rsi
// test:
//   leaq    12(%rsi), %rbx
//   testq   %rdi, %rdi
//   jge     .L2
//   movq    %rdi, %rbx
//   imulq   %rsi, %rbx
//   movq    %rdi, %rdx
//   orq     %rsi, %rdx
//   cmpq    %rsi, %rdi
//   cmovge  %rdx, %rbx
//   ret
// .L2:
//   idivq   %rsi, %rdi
//   cmpq    $10, %rsi
//   cmovge  %rdi, %rbx
//   ret

short test(short x, short y)
{
    // %rbx = y + 12;
    short val = y + 12;
    // y >= 0 --> L2
    if (x < 0)
    {
        // val = x
        // val = x * y
        // movq %rdi, %rdx  val = x
        // orq %rsi, %rdx   val = x | y
        if (x - y >= 0)
            val = x | y;
        else
            val = x * y;
    } else if (y - 10 >= 0)
        val = x / y;
    return val;
}
