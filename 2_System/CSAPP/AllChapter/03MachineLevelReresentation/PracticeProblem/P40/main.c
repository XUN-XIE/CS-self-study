/*************************************************************************
 @Author: XieXun
 @Created Time : Sat  5 Dec 09:32:11 2020
 @File Name: main.c
 @Description:
 ************************************************************************/

#include <stdio.h>

void fix_set_diag(fix_matrix A, int val)
{
    long i;
    for (i = 0; i < N; i++)
        A[i][i] = val;
}

void OP_fix_set_diag(fix_matrix A, int val)
{
    // movl --> (A + 0) = val
    // %rax += 68
    // %rax != 1088
    //
    // (A + 68) = val
    // A += 68
    //
    // cols = 8
    // total 136
    // rows = 17
    long * end = A + 136;
    for (long * i = A; i != A+136; i += 9)
        *A = val;
}
