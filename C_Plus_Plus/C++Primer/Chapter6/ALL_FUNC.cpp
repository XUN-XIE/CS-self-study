// Firstly include the header file
#include "ALL_FUNC.hpp"

// Then, define all functions here

int fact(int num)
{
    int result = 1;
    while (num >= 1)
        result *= num--;

    return result;
}



int abs(int num)
{
    if (num >= 0)
        return num;
    else
        return -num;
}



int generate()
{
    static int num = 0;

    return num++;
}