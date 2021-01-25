/*************************************************************************
 @Author: XieXun
 @Created Time : Fri 27 Nov 11:02:00 2020
 @File Name: main.c
 @Description:
 ************************************************************************/

#include <stdio.h>
#include <ctype.h>
// four bits
int B2T(char * str)
{
    // 又忘记初始化了！！！函数内不初始化，赋值是有问题的！！！C++也是
    int result = 0;
    int expo = 1;
    for (int index = 3; index >= 1; index--)
    {
        result += expo * (str[index] - '0');
        expo *= 2;
    }
    if (str[0] == '0')
        return result;
    if (str[0] == '1')
        return result - expo;
    return 0;
}

int B2U(char * str)
{
    int result = 0;
    int expo = 1;
    for (int index = 3; index >= 0; index--)
    {
        result += expo * (str[index] - '0');
        expo *= 2;
    }
    return result;
}

int main()
{
    // line 1
    // line 2 0x1   0001    1   1
    char str2[5] = "0001";
    printf("line 2: 0001   %d   %d  \n", B2U(str2), B2T(str2));
    // line 3 0xB   1011    11  -5
    char str3[5] = "1011";
    printf("line 3: 1011   %d   %d  \n", B2U(str3), B2T(str3));
    // line 4 0x2   0010    2   2
    char str4[5] = "0010";
    printf("line 4: 0010   %d   %d  \n", B2U(str4), B2T(str4));
    // line 5 0x7   0111    7   7
    char str5[5] = "0111";
    printf("line 5: 0111   %d   %d  \n", B2U(str5), B2T(str5));
    // line 6 0xC   1100    12  -4
    char str6[5] = "1100";
    printf("line 6: 1100   %d   %d  \n", B2U(str6), B2T(str6));


}
