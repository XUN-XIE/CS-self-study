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
    printf("res = %d\n", res);
    printf("result =  %x\n", htonl( *(int *)dst ) );
    free(dst);
    dst = NULL;
}

void
hex_to_deci( int src )
{
    char *dst = (char *)malloc(sizeof(char) * 16);
    int srchl = ntohl(src);
    const char * res = inet_ntop( AF_INET, &srchl, dst, 16);
    printf("res = %s\n", res);
    printf("result = %s\n", dst);
}

int main()
{
    char * l1 = "107.212.122.205";
    char * l2 = "64.12.149.13";
    char * l3 = "107.212.96.29";
    const char * str[3] = {
        l1, l2, l3
    };
    for (int i = 0; i < 3; i++)
    {
        printf("Answer %d:\n", i+1 );
        deci_to_hex(str[i]);
        printf("\n");
    }

    int l4 = 0x00000080;
    int l5 = 0xFFFFFF00;
    int l6 = 0x0A010140;
    int hex[3] = {
        0x00000080, 0xFFFFFF00, 0x0A010140
    };
    for (int i = 4; i <= 6; i++)
    {
        printf("Answer %d:\n", i );
        hex_to_deci(hex[i - 4]);
        printf("\n");
    }

}

