/*************************************************************************
 @Author: XieXun
 @Created Time : Fri 27 Nov 09:06:34 2020
 @File Name: main.c
 @Description:
 ************************************************************************/

#include <stdio.h>
#include <ctype.h>
long long unsigned evaluateHexa(char * str)
{
    long long result = 0;
    long long expo = 1;
    for (int i = 7; i >= 0; i--)
    {
        if (isalpha(str[i]))
        {
            result += expo * (str[i] - 'a' + 10);
        }
        else
        {
            result += expo * (str[i] - '0');
        }
        expo *= 16;
    }
    return result;
}

int main()
{
    char x[9] = "87654321";
    long long evalX = evaluateHexa(x);
    printf("x = %x\n", evalX);

    // Problem A
    char maskA[9] = "000000ff";
    long long evalMaskA = evaluateHexa(maskA);
    printf("Problem A : %x\n", evalX & evalMaskA);

    // Problem B
    // 利用 0xffffff00, 0 ^ a = a
    char maskB[9] = "ffffff00";
    long long evalMaskB = evaluateHexa(maskB);
    printf("Problem B : %x\n", evalMaskB ^ evalX);
    
    // Problem C
    // 利用 0x000000ff, 1 | a = 1, 0 | a = a
    char maskC[9] = "000000ff";
    long long evalMaskC = evaluateHexa(maskC);
    printf("Problem C : %x\n", evalMaskC | evalX);
}
