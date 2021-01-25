/*************************************************************************
 @Author: XieXun
 @Created Time : Wed  2 Dec 20:56:07 2020
 @File Name: main.c
 @Description:
 ************************************************************************/

#include <stdio.h>

long shift_left4_rightn(long x, long n)
{
    x <<= 4;
    x >>= n;
    return x;
}

// %rax <-- tmp
// %rdi <-- x
// %rsi <-- n

int main()
{
    // sal 后面的字节数，是根据destination value的字节决定的
    printf("movq    %%rdi, %%rax    Get x\n");
    printf("salq    $ 4, %%rax        x<<=4\n");
    printf("movl    %%esi, %%ecx      Get n (4 bytes)\n");
    
    // if the source is a variable, it need to be fron %cl register
    printf("sarq    %%cl, %%rax      x >>= n\n");
}
