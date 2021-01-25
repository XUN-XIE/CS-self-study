/*************************************************************************
 @Author: XieXun
 @Created Time : Wed 16 Dec 09:27:15 2020
 @File Name: main.c
 @Description:
 ************************************************************************/

#include <stdio.h>

/*
 *  C = 1024 --> m = 10
 *  b = 4
 *  s = 6 --> S = 64;
 *  
 *  j --> j+1 --> 16 * 8
 *  会发生覆盖，在读取第二个element之前，被其他的覆盖掉原始 set
 *
 *
 *  C = 2048 --> m = 11
 *  b = 4
 *  s = 7 --> S = 128;
 *  刚好每个set 两个element
 *  因此循环到第二个element时，直接读取
 *
 */
int main()
{
    printf("Problem A: 512\n");
    printf("Problem B: 256\n");
    printf("Problem C: 256 / 512 = 50%%\n");
    printf("Problem D: (512 - 128) / 512 = 75%%\n");

}
