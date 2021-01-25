/*************************************************************************
 @Author: XieXun
 @Created Time : Thu 31 Dec 15:14:41 2020
 @File Name: wcat.c
 @Description:
 ************************************************************************/

#include <stdio.h>
#include <errno.h>
#include <stdlib.h>

void
mainLogic( char * filename )
{
    FILE * input = fopen( filename, "r");
    if ( input == NULL )
    {
        printf("wcat: cannot open file\n");
        // printf("%s ", filename);
        // perror("wrong happened\n");
        exit( 1 );
    }
    
    int tmp;
    while ( ( tmp = fgetc( input ) ) != EOF )
        putchar( tmp );
    fclose( input );
}

int main(int argc, char *argv[], char *env[])
{
    if (argc < 2)
        exit(0);

    int count = 1;
    while (argv[count])
        mainLogic( argv[count++]);
}
