/*************************************************************************
 @Author: XieXun
 @Created Time : Thu 26 Nov 23:53:01 2020
 @File Name: main.c
 @Description:
 ************************************************************************/

#include <stdio.h>
#include <string.h>
int main()
{
    const char * m = "mnopqr";
    unsigned char * ap = (unsigned char *)m;
    for (int i = 0; i < strlen(m); i++)
    {
        printf(" %.2x", ap[i]);
    }
    printf("\n");
}
