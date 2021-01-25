/*************************************************************************
 @Author: XieXun
 @Created Time : Mon 14 Dec 10:20:45 2020
 @File Name: main.c
 @Description:
 ************************************************************************/

#include <stdio.h>

int main()
{
    printf("word Med3 = [\n");
    printf("        A <= B && A >= C : A\n");
    printf("        A <= C && A >= B : A\n");
    printf("        B <= A $$ B >= C : B\n");
    printf("        B <= C $$ B >= A : B\n");
    printf("        1 : C\n");
    return 0;
}
