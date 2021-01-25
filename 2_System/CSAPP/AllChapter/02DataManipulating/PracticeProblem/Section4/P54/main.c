/*************************************************************************
 @Author: XieXun
 @Created Time : Sun 29 Nov 12:56:42 2020
 @File Name: main.c
 @Description:
 ************************************************************************/

#include <stdio.h>

int main()
{
    printf("A. True. 因为double的fractional有 51 位，可以轻松表示 32 位的 int\n");
    printf("B, False. 比如 一个 x > 2^22 ,那么就会发生truncate 在转float时\n");
    printf("C. False. 因为 float 精度没有 double 高，比如 1E2^12 就会truncate或者 精度不够\n");
    printf("D. True\n");
    printf("E. True， 只会改变 sign bit 不妨碍\n");
    printf("F. True, 都被转成了 double 计算，无精度丢失\n");
    printf("G. True， 书中有写，虽然会overflow\n");
    printf("参考答案了，第一次做错了。\n");
    printf("H. False. 这个题主要的考察问题是 round 并不是精度转化， 因为有分配律！！！！ 比如 f = 1E29, d = 1。那么因为round，就会导致式子左面为0，右面1\n");
}
