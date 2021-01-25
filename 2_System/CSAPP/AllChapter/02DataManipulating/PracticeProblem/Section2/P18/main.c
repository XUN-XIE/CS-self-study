/*************************************************************************
 @Author: XieXun
 @Created Time : Fri 27 Nov 11:46:28 2020
 @File Name: main.c
 @Description:
 ************************************************************************/

#include <stdio.h>
#include <ctype.h>
// four bits
int B2T(char * str, int size)
{
    // 又忘记初始化了！！！函数内不初始化，赋值是有问题的！！！C++也是
    int result = 0;
    int expo = 1;
    for (int index = size - 1; index >= 0; index--)
    {
        result += expo * (str[index] - '0');
        expo *= 2;
    }
    return result;
}

int main()
{
    printf("被这道题的 负号误导了，需要注意，就是单纯的衡量十六进制数然后取反\n");
    printf("提醒自己一点！8的二进制，全都写错了，都写成了 0100， 正确的是 1000\n");
    // A 0x2e0  001011100000
    // B -0x58   01011000
    // C 0x28   00101000
    // D -0x30   00110000
    // E 0x78   01111000
    // F 0x88   10001000
    // G 0x1f8  000111111000
    // H 0xC0   11000000
    // I -0x48   01001000
    const int sizeA = 13;
    char strA[sizeA] = "001011100000";
    printf("A = %d\n", B2T(strA, sizeA - 1));

    const int sizeB = 9;
    char strB[sizeB] = "01011000";
    printf("B = %d\n", -B2T(strB, sizeB - 1));

    const int sizeC = 9;
    char strC[sizeC] = "00101000";
    printf("C = %d\n", B2T(strC, sizeC - 1));

    const int sizeD = 9;
    char strD[sizeD] = "00110000";
    printf("D = %d\n", -B2T(strD, sizeD - 1));

    const int sizeE = 9;
    char strE[sizeE] = "01111000";
    printf("E = %d\n", B2T(strE, sizeE - 1));

    const int sizeF = 9;
    char strF[sizeF] = "10001000";
    printf("F = %d\n", B2T(strF, sizeF - 1));

    const int sizeG = 13;
    char strG[sizeG] = "000111111000";
    printf("G = %d\n", B2T(strG, sizeG - 1));
    
    const int sizeH = 9;
    char strH[sizeH] = "11000000";
    printf("H = %d\n", B2T(strH, sizeH - 1));

    const int sizeI = 9;
    char strI[sizeI] = "01001000";
    printf("I = %d\n", -B2T(strI, sizeI - 1));

    
}
