/*************************************************************************
 @Author: XieXun
 @Created Time : Wed 16 Dec 10:05:04 2020
 @File Name: MatrixMulplication.c
 @Description:
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#define N 2

void
basic(const int A[][N], const int B[][N], int C[][N])
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            int sum = 0;
            for (int k = 0; k < N; k++)
                sum += A[i][k] * B[k][j];
            C[i][j] += sum;
        }
    }
}


void
best(const int A[][N], const int B[][N], int C[][N])
{
    for (int k = 0; k < N; k++)
    {
        for (int i = 0; i < N; i++)
        {
            int r = A[i][k];
            for (int j = 0; j < N; j++)
                C[i][j] += r * B[k][j];
        }
    }
}

void print(int (*mat)[N])
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
            printf("%d ", mat[i][j]);
        printf("\n");
    }
}

int main()
{
//    int (*A)[N] = (int (*)[N]) malloc(sizeof(int) * 4);
    int A[N][N] = {
        {
            0,1
        },
        {
            2,3
        }
    };
    //A[0][0] = 0;
    //A[0][1] = 1;
    //A[1][0] = 2;
    //A[1][1] = 3;

    // int (*B)[N] = (int (*)[N]) malloc(sizeof(int) * 4);
    int B[N][N] = {
        {
            4,5
        },
        {
            6,7
        }
    };
//    /*
    int C[N][N] = {
        0,0,0,0
    };
    basic(A, B, C);
    print(C);
    
    int D[N][N] = {
        0,0,0,0
    };
    best(A, B, D);
    print(D);
// */
}
