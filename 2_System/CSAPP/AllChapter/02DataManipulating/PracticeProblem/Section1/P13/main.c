/*************************************************************************
 @Author: XieXun
 @Created Time : Fri 27 Nov 09:32:24 2020
 @File Name: main.c
 @Description:
 ************************************************************************/

#include <stdio.h>

int bis(int x, int m)
{
    return x | m;
}

int bic(int x, int m)
{
    return x & (~m);
}

int bool_or(int x, int y)
{
    int result = bis(x, y);
    return result;
}

int bool_xor(int x, int y)
{
    // a⊕b = (¬a ∧ b) ∨ (a ∧¬b)
    // a ^ b =( (~a) & b ) | ( a & (~b) )
    int result = bis(bic(x,y), bic(y,x));
    return result;
}

int main()
{
    // test my function
    // case 1 : x = 2 = 010, y = 4 = 100
    // result : 110 = 6, 110 = 6
    printf("x = 2, y = 4 : or = %d, xor = %d\n", bool_or(2,4), bool_xor(2,4));
    
    // case 2 : x = 5 = 101, y = 3 = 011
    // result : 111 = 7, xor = 110 = 6 
    printf("x = 7, y = 3 : or = %d, xor = %d\n", bool_or(5,3), bool_xor(5,3));
}
