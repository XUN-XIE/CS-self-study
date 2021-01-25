/*************************************************************************
 @Author: XieXun
 @Created Time : Thu 21 Jan 10:53:14 2021
 @File Name: main.c
 @Description:
 ************************************************************************/

#include <stdio.h>
#include <arpa/inet.h>
#include <stdlib.h>

void
deci_to_hex( const char * src )
{
    void *dst = malloc(sizeof(int));
    int res = inet_pton( AF_INET, src, dst);
    if ( res == 1 )
        printf("%x\n", htonl( *(int *)dst ) );
    else if ( res == 0 )
    {
        printf("src is invalid in inet_pton function\n");
        fflush(stdout);
        exit(1);
    }
    else
    {
        printf("wrong happened in inet_pton function\n");
        fflush(stdout);
        exit(1);
    }
    free(dst);
    dst = NULL;
}

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("the number of argument is invalid\n");
        fflush(stdout);
        exit(1);
    }

    deci_to_hex( argv[1] );
}
