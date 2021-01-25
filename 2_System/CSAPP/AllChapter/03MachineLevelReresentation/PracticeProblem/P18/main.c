/*************************************************************************
 @Author: XieXun
 @Created Time : Thu  3 Dec 20:21:00 2020
 @File Name: main.c
 @Description:
 ************************************************************************/

#include <stdio.h>

// short test(short x, short y, short z)
// x in %rdi, y in %rsi, z in %rdx
// test:
//   leaq    (%rdx,%rsi), %rax
//   subq    %rdi, %rax
//   cmpq    $5, %rdx
//   jle     .L2
//   cmpq    $2, %rsi
//   jle     .L3
//   movq    %rdi, %rax
//   idivq   %rdx, %rax
//   ret
// .L3:
//   movq    %rdi, %rax
//   idivq   %rsi, %rax
//   ret
// .L2:
//   cmpq    $3, %rdx
//   jge     .L4
//   movq    %rdx, %rax
//   idivq   %rsi, %rax
// .L4:
//   rep; ret


short test(short x, short y, short z)
{
    short val =  z + y - x;
    if (z > 5)
   {
        if (y > 2)
            val = x/z;
        else
            val = x/y;
    } else if(z < 3)
        val = z/y;
    return val;
}
