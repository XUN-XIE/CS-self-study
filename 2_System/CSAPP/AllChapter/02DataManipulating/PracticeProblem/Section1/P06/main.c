/*************************************************************************
 @Author: XieXun
 @Created Time : Thu 26 Nov 23:22:36 2020
 @File Name: main.c
 @Description:
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>

int * maxMatch(char * str1, char * str2)
{
    int maxCount = 0;
    int maxShift = 0;
    for (int shift = 0; shift < 32; shift++)
    {
        int thisCount = 0;
        for (int index = 0; index < 32; index++)
        {
            if (str1[index] == str2[index])
            {
                thisCount++;
            }
        }
        if (thisCount > maxCount)
        {
            maxCount = thisCount;
            maxShift = shift;
        }

        // 右移动
        char last = str2[31];
        for (int index = 31; index > 0; index--)
        {
            str2[index] = str2[index-1];
        }
        str2[0] = last;
    }
    
    int * result = (int *)malloc(sizeof(int)*2);
    result[0] = maxCount;
    result[1] = maxShift;
    return result;
}


int main()
{
    // Problem A
    // int 0x0027C8F8 = 
    // 0    0    2    7    C    8    F    8
    // 0000 0000 0010 0111 1100 1000 1111 1000
    // float 0x4A1F23E0 = 
    // 4    A    1    F    2    3    E    0
    // 0100 1010 0001 1111 0010 0011 1110 0000
    printf("ProblemA:\n  int = 0000 0000 0010 0111 1100 1000 1111 1000\n  float = 0100 1010 0001 1111 0010 0011 1110 0000\n");

    // Problem B
    // 直接暴力解法吧
    char str1[33] = "00000000001001111100100011111000";
    char str2[33] = "01001010000111110010001111100000";
    int * result = maxMatch(str1, str2);
    printf("the max matches is %d, the max shift is %d\n", result[0], result[1]);
    free(result);

    // Problem C
    // maxshift = 2
    // 0000 0000 0010 0111 1100 1000 1111 1000
    // 0001 0010 1000 0111 1100 1000 1111 1000
    //    * **** *** 
    printf("0000 0000 0010 0111 1100 1000 1111 1000\n0001 0010 1000 0111 1100 1000 1111 1000\n"
           "   * **** ***                          \n"
           "the different part is at beginning\n");
}
