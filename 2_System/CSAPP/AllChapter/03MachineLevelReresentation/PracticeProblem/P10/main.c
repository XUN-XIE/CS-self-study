/*************************************************************************
 @Author: XieXun
 @Created Time : Wed  2 Dec 20:56:07 2020
 @File Name: main.c
 @Description:
 ************************************************************************/

#include <stdio.h>

// x in %rdi, y in %rsi, z in %rdx
// arith3:
//   orq     %rsi, %rdx
//   sarq    $9, %rdx
//   notq    %rdx
//   movq    %rdx, %bax
//   subq    %rsi, %rbx
//   ret

short arith3(short x, short y, short z)
{
    short p1 = y | z; 
    short p2 = p1 >> 9; 
    short p3 = ~p2;
    short p4 = y - p3; 

    return p4;
}
