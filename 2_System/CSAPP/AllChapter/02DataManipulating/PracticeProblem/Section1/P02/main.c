/*************************************************************************
 @Author: XieXun
 @Created Time : Thu 26 Nov 20:01:36 2020
 @File Name: PracticeProblem2_2.c
 @Description:
 ************************************************************************/

#include <stdio.h>

long int exponential(int num)
{
    long int result = 1;
    for (int i = 0; i < num; i++)
    {
        result *= 2;
    }
    return result;
}

int main()
{
    // Line 1
    // Line 2
    long long int v2_23 = exponential(23);
    // hexadecimal value 23 = 3 + 4 * 5
    printf("line 2 decimal value are %lld, hexadecimal value is 0x800000\n", v2_23);
    
    // line 3
    int decimal3 = 32768;
    int count3 = 0;
    while (decimal3 > 1)
    {
        decimal3 /= 2;
        ++count3;
    }
    // 15 = 3 * 4 * 3
    printf("line 3 the n is %d, the hexadecimal is 0x8000\n", count3);
    
    // line 4
    // n = 1 + 4 * 3 = 13
    printf("line 4 the n is 13, the decimal are %ld\n", exponential(13));

    // line 5
    // 12 = 0 + 4 * 3
    printf("line 5 the decimal are %ld, the hexadecimal is 0x1000\n", exponential(12));

    // line 6
    // 6 = 2 + 4 * 1
    printf("line 6 the n is 6, the hexadecimal is 0x40\n");

    // line 7
    // n = 0 + 4 * 2 = 8
    printf("line 7 the n is 8, the decimal is %ld\n", exponential(8));
    return 0;
}
