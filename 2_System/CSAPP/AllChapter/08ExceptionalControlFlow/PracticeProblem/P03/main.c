/*************************************************************************
 @Author: XieXun
 @Created Time : Wed 23 Dec 19:12:10 2020
 @File Name: main.c
 @Description:
 ************************************************************************/

#include <stdio.h>

int main()
{
    // 解析 waitpid(-1, NULL, 0)
    // 第一个参数 -1, 表明要等待所有的子进程
    // 第二个参数 NULL, 默认情况
    // 第三个参数 0, 默认情况
    // 所以这个 waitpid 是要等待子进程结束的
    printf("Child Process:\n");
    printf("936\n\n");  // 因为子进程中，exit 在最后一行，所以 36 也要打印

    printf("Parent Process:\n");
    printf("036\n");

    printf("\n参考答案，有细节的 process graph\n");
}
