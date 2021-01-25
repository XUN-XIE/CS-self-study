/*************************************************************************
 @Author: XieXun
 @Created Time : Sun 29 Nov 09:45:08 2020
 @File Name: main.c
 @Description:
 ************************************************************************/

#include <stdio.h>

int main()
{
    // bias = 1
    
    printf("第一次做题错误原因, denormalized case 的E算错了，E = 1 - bias。 与normalized case 的 E = e - bias 区分开来\n");
    printf("Bits        e   E   2^E     f       M       2^E * M     V   Decimal\n");
    printf("0 00 00     0   0   1       0       0       +0\n");
    printf("0 00 01     0   0   1       0.25    0.25    0.25\n");
    printf("0 00 10     0   0   1       0.5     0.5     0.5\n");
    printf("0 00 11     0   0   1       0.75    0.75    0.75\n");
    printf("0 01 00     1   0   1       0       1       1\n");
    printf("0 01 01     1   0   1       0.25    1.25    1.25\n");
    printf("0 01 10     1   0   1       0.5     1.5     1.5\n");
    printf("0 01 11     1   0   1       0.75    1.75    1.75\n");
    printf("0 10 00     2   1   2       0       1       2\n");
    printf("0 10 01     2   1   2       0.25    1.25    2.5\n");
    printf("0 10 10     2   1   2       0.5     1.5     3\n");
    printf("0 10 11     2   1   2       0.75    1.75    3.5\n");
    printf("0 11 00                                                 INFINITY\n");
    printf("0 11 01                                                 Nan\n");
    printf("0 11 10                                                 Nan\n");
    printf("0 11 11                                                 Nan\n");
    
}
