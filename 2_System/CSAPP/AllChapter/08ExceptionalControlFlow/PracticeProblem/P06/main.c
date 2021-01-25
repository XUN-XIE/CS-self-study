/*************************************************************************
 @Author: XieXun
 @Created Time : Wed 23 Dec 19:50:46 2020
 @File Name: main.c
 @Description:
 ************************************************************************/

#include <stdio.h>

int main(int argc, char *argv[], char *envp[])
{
    int i;

    printf("Command-line arguments:\n");

    for (i=0; argv[i] != NULL; i++)
        printf(" argv[%2d]: %s\n", i, argv[i]);
    
    printf("\n");
    
    printf("Environment variables:\n");
    
    for (i=0; envp[i] != NULL; i++)
        printf(" envp[%2d]: %s\n", i, envp[i]);

    return 0;
}
