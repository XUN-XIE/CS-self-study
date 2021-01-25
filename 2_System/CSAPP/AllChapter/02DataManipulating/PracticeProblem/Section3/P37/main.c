/*************************************************************************
 @Author: XieXun
 @Created Time : Sat 28 Nov 11:04:53 2020
 @File Name: main.c
 @Description:
 ************************************************************************/

#include <stdio.h>
#include <limits.h>



int main()
{
    printf("Problem A: 这里的的 asize 虽然是 64 位，没有发生overflow，但是传入 malloc 中，参数类型还是32位，会发生 truncate，所以还是会可能overflow\n");
    printf("增加一个条件判断，和上一题中一样，声明一个 临时的 size_t 类型变量，然后判断和 aszie 是否相等， 不等就报错\n");

    return 0;
}
