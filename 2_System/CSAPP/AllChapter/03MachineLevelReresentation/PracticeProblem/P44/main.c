/*************************************************************************
 @Author: XieXun
 @Created Time : Sat  5 Dec 10:25:32 2020
 @File Name: main.c
 @Description:
 ************************************************************************/

#include <stdio.h>

int main()
{
    printf("offest for every type       total size      alignment\n");
    printf("ProblemA : i + c = 5   total=24\n");
    printf("ProblemB : i = c = s = j = 8    total = 32\n");
    printf("ProblemC : w = c = 16   total=32 \n");
    printf("ProblemD : w = c = 16   total=32 \n");
    printf("ProblemE : a = 32*2, t = 24     total = 96\n");
    
    // A:   0   4   8   16  24      alignment = 8   --> total = 32
    //      i   c   j   d   
    //      0   2   6   14  
}
