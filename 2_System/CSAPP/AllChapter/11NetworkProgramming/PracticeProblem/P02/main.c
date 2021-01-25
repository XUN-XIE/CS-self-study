/*************************************************************************
 @Author: XieXun
 @Created Time : Thu 21 Jan 10:53:14 2021
 @File Name: main.c
 @Description:
 ************************************************************************/

#include <stdio.h>
#include <arpa/inet.h>
#include <stdlib.h>
#include <ctype.h>

void
hex_to_deci( int src )
{
    char *dst = (char *)malloc(sizeof(char) * 16);
    int srchl = ntohl(src);
    const char * res = inet_ntop( AF_INET, &srchl, dst, 16);
    if (res)
        printf("%s\n", dst);
    else
    {
        printf("something wrong happened in inet_ntop function\n");
        fflush(stdout);
        exit(1);
    }
}

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("the number of argument is invalid!\n");
        fflush(stdout);
        exit(1);
    }

    unsigned int input = 0;
    
    char *cursor = argv[1];
    if (cursor[1] == 'x' || cursor[1] == 'X')
        cursor += 2;
    for ( ; *cursor; cursor++ )
    {
        input *= 16;
        int chr = *cursor;
        if (isdigit(chr))
            input += chr - '0';
        else
            input += chr - 'a' + 10;
    }
    printf("input = %u\n", input);
    hex_to_deci(input);
    return 0;
}
