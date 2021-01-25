/*************************************************************************
 @Author: XieXun
 @Created Time : Fri 27 Nov 18:44:09 2020
 @File Name: main.c
 @Description:
 ************************************************************************/

#include <stdio.h>

// assume (or maybe true?)
// right shifts of signed values are per- formed arithmetically
// right shifts of unsigned values are performed logically


int func1(unsigned word)
{
    return (int) ((word << 24) >> 24);
}

int func2(unsigned word)
{
    return   ((int)word << 24) >> 24;
}


// Just remember that hex digits 8 through F have their most significant bits equal to 1.
int main()
{   
    //              w           func1       func2
    // line 1 : 0x00000076  0x00000076  0x00000076
    // line 2 : 0x87654321  0x00000021  0x00000021
    // line 3 : 0x000000C9  0x000000C9  0xffffffC9
    // line 4 : 0xEDCBA987  0x00000087  0xffffff87
    printf("line 1: %x  %x\n", func1(0x00000076), func2(0x00000076));
    printf("line 2: %x  %x\n", func1(0x87654321), func2(0x87654321));
    printf("line 3: %x  %x\n", func1(0x000000C9), func2(0x000000C9));
    printf("line 4: %x  %x\n", func1(0xEDCBA987), func2(0xEDCBA987));
    
    printf("Problem B :\n"
            "func1 直接截取4字节数据的最小的那个字节的(unsigned)数值\n"
            "func2 截取4字节数据的最小的那个字节的 binary 形式所表示的 signed 值\n");
    return 0;
}
