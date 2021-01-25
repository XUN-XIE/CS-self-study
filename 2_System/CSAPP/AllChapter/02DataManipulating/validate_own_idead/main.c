/*************************************************************************
 @Author: XieXun
 @Created Time : Thu 26 Nov 22:12:21 2020
 @File Name: main.c
 @Description:
 ************************************************************************/

#include <stdio.h>

int main()
{
    // 验证取地址符作用后变量的类型？
    int x = 0;
    unsigned char * tmp = (unsigned char *) &x;
    printf("%x\n%p\n", tmp, &x);
    printf("%x\n", &x);
    
    for (int i = 0; i < sizeof(int); i++)
    {
        printf(" %.2x\n", tmp[i]);
    }


    printf("%lu\n", sizeof(int *));


    // float double 也能使用位运算？
    printf("\n\nfloat double 也能使用位运算？\n");
    int bitShiftInt = 32 >> 2;
    int bitShiftInt2 = 32 << 2;
    printf("%d\n", bitShiftInt);
    printf("%d\n", bitShiftInt2);
    return 0;
}
