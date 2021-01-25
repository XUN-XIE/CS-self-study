/*************************************************************************
 @Author: XieXun
 @Created Time : Fri 27 Nov 10:05:39 2020
 @File Name: main.c
 @Description:
 ************************************************************************/

#include <stdio.h>
#include <ctype.h>
long long unsigned evaluateHexa(char * str)
{
     long long result = 0;
     long long expo = 1;
     for (int i = 1; i >= 0; i--)
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
    char a[3] = "55";
    char b[3] = "46";
    long long evalA = evaluateHexa(a);
    long long evalB = evaluateHexa(b);
    printf("%.2x\t1\n", evalA & evalB);
    printf("%.2x\t1\n", evalA | evalB);
    printf("(~a = %x, ~b = %x)\n", ~evalA, ~evalB);
    printf("%.2x\t0\n", (~evalA) | (~evalB));
    printf("%.2x\t1\n", evalA & 0);
}
