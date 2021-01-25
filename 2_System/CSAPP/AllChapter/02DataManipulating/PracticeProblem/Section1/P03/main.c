/*************************************************************************
 @Author: XieXun
 @Created Time : Thu 26 Nov 20:35:55 2020
 @File Name: main.c
 @Description:
 ************************************************************************/

#include <stdio.h>

void decimalToBinary(int num)
{
    int bits[8];
    for (int i = 0; i < 8; i++)
    {
        bits[i] = num % 2;
        num /= 2;
    }
    
    for (int i = 7; i >= 0; i--)
    {
        printf("%d", bits[i]);
    }
}

int binaryToDecimal(char * string)
{
    int result = 0;
    int expo = 1;
    // 第一次写把次序搞反了
    for (int i = 7; i >= 0; i--)
    {
        // 这里忘记转换了，导致 '1' '0' 并不是对应 0. 1
        result += (string[i] - '0') * expo;
        expo *= 2;
    }
    return result;
}

int main()
{
    // line 1
    // line 2 binary is 10011110, hexadecimal is 0x9E
    int decimal2 = 158;
    printf("line 2 binary rep is ");
    decimalToBinary(decimal2);
    printf(", the decimal is 0x9E\n");

    // line 3 binary is 01001100, hexadecimal is 0x4C
    int decimal3 = 76;
    printf("line 3 binary rep is ");
    decimalToBinary(decimal3);
    printf(", the decimal is 0x4C\n");
    
    // line 4 binary is 10010001, hexadecimal is 0x91
    int decimal4 = 145;
    printf("line 4 binary rep is ");
    decimalToBinary(decimal4);
    printf(", the decimal is 0x91\n");


    /*---------------这里的前三个C风格字符串其实写的有问题！因为我想存储size=8的字符串，那么我应该把数组初始化为size = 9，因为需要留一位给 '\0'----------------*/

    // line 5 decimal 174, hexadecimal is 0xAE
    char binary5[8] = "10101110";
    printf("line 5 decimal are %d, hexadecimal is 0xAE\n", binaryToDecimal(binary5));

    // line 6 decimal 60, hexadecimal is 0x3C
    char binary6[8] = "00111100";
    printf("line 6 decimal are %d, hexadecimal is 0x3C\n", binaryToDecimal(binary6));

    // line 7 decimal 241, hexadecimal is 0xF1
    char binary7[8] = "11110001";
    printf("line 7 decimal are %d, hexadecimal is 0xF1\n", binaryToDecimal(binary7));


    /*---------------这里的字符串数组初始化是对的，但是第一次写没发现，还是初始化的9，导致最后输出的字符是把后面的两个字符串都打印出来了，正好印证了视频中教授讲的，C不会chck bound！！！所以需要自己check bound----------------*/  

    // line 8 binary is 0111 0101
    char binary8[9] = "01110101";
    printf("line 8 decimal is %d, binary is %s\n", binaryToDecimal(binary8), binary8);

    // line 9 binary is 1011 1101
    char binary9[9] = "10111101";
    printf("line 9 decimal is %d, binary is %s\n", binaryToDecimal(binary9), binary9);

    // line 10 binary is 1111 0101
    char binary10[9] = "11110101";
    printf("line 10 decimal is %d, binary is %s\n", binaryToDecimal(binary10), binary10);


}
