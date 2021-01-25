/*************************************************************************
 @Author: XieXun
 @Created Time : Tue 15 Dec 10:41:28 2020
 @File Name: mian.c
 @Description:
 ************************************************************************/

#include <stdio.h>

int main()
{
    printf("Ranking: clear1, clear2, clear3\n");
    printf("clear1 can delete every vector by 1-stride\n");
    printf("clear2 need 3-stride to delete(because vec and acc in struct is suqentilly allocated)\n");
    printf("clear3 need 6-stride for outside loop\n");
}
