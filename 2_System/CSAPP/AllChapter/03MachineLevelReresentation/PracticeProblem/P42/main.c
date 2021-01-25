/*************************************************************************
 @Author: XieXun
 @Created Time : Sat  5 Dec 09:46:09 2020
 @File Name: main.c
 @Description:
 ************************************************************************/

#include <stdio.h>

struct ACE {
    short      v;
    struct ACE *p;
};

short test(struct ACE *ptr)
{
    int fac = 1;
    while (ptr)
    {
        // %rax = v * 1
        // %rdi = ptr = p;
        fac *= ptr->v;
        ptr = ptr->p;
    }
}
