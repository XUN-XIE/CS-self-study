/*************************************************************************
 @Author: XieXun
 @Created Time : Fri  4 Dec 19:20:16 2020
 @File Name: main.c
 @Description:
 ************************************************************************/

#include <stdio.h>

void fibonacciWhile(int n)
{
    int count1 = 1;
    int count2 = 1;
    while (count2 < n)
    {
        int tmp = count1 + count2;
        count1 = count2;
        count2 = tmp;
        printf("%d\n", count2);
    }
}

void fibonacciGuardedDo(int n)
{
    int count1 = 1;
    int count2 = 1;
    int tmp;
    if (!(count2 < n))
        goto done;
loop:
        tmp = count1 + count2;
        count1 = count2;
        count2 = tmp;
        printf("%d\n", count2);
        if (count2 < n)
            goto loop;
done:
        return;
}

int main()
{
    // fibonacciWhile(10);
    fibonacciGuardedDo(10);
}
