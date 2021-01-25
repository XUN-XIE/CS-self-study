/*************************************************************************
 @Author: XieXun
 @Created Time : Thu  3 Dec 21:33:12 2020
 @File Name: main.c
 @Description:
 ************************************************************************/

#include <stdio.h>

short test_one(unsigned short x)
{
    short val = 1;
    while (x)
    {
        val = val ^ x; 
        x = x >> 1;
    }
    return val & 0;
}

int main()
{
    printf("Problem A: jump to middle\n");

}
