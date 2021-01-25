/*************************************************************************
 @Author: XieXun
 @Created Time : Fri 27 Nov 18:11:46 2020
 @File Name: main.c
 @Description:
 ************************************************************************/

#include <stdio.h>

int main()
{
    int RANGE = 2147483647;
    printf("            Type    Evaluation\n");
    printf("line 1 :    unsigned    %d\n", ( -RANGE - 1 == 2147483648U ));  // 1
    printf("line 2 :    signed      %d\n", ( -RANGE - 1 < RANGE ));         // 1
    printf("line 3 :    unsigned    %d\n", ( -RANGE - 1U < RANGE ));        // 0
    printf("line 4 :    signed      %d\n", ( -RANGE - 1 < -RANGE ));        // 1
    printf("line 5 :    unsigned    %d\n", ( -RANGE - 1U < -RANGE ));       // 1
}
