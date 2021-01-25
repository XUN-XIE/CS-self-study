/*************************************************************************
 @Author: XieXun
 @Created Time : Wed  2 Dec 20:56:07 2020
 @File Name: main.c
 @Description:
 ************************************************************************/

#include <stdio.h>

// short scale3(short x, short y, short z)
// x in %rdi, y in %rsi, z in %rdx
// 
// scale3:
//   leaq (%rsi,%rsi,9), %rbx
//   leaq (%rbx,%rdx), %rbx
//   leaq (%rbx,%rdi,%rsi), %rbx
//   ret

short scale3(short x, short y, short z)
{
    // wrong answer!
    // %rbx 64bits;
    // long tmp = 10 * y;
    // tmp =  tmp + z;
    // tmp = tmp + x * y;
    // return tmp;

    short t = 10 * y + z + y * x;
    return t;
}

int main()
{
   printf("read the source code!\n");
}
