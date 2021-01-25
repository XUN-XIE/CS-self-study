/*************************************************************************
 @Author: XieXun
 @Created Time : Thu 31 Dec 16:00:07 2020
 @File Name: reverse.c
 @Description:
 ************************************************************************/

#include "List.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node {
    char *Element;
    Position Next;    
};

void
checkFile( FILE * stream , char * filename )
{
    if ( !stream )
    {
        fprintf( stderr, "reverse: cannot open file '%s'\n", filename);
        exit( 1 );
    }
}

void
checkMalloc( void * ptr )
{
    if ( !ptr )
    {
        fprintf( stderr, "malloc failed\n");
        exit(1);
    }
}

void
getInOut( FILE ** input, FILE ** output, int argc, char *argv[] )
{
    if (argc > 3)
    {
        fprintf( stderr, "usage: reverse <input> <output>\n");
        exit(1);
    }
    // printf("arguments = %d\n %s %s\n", argc, argv[1], argv[2]);
    if (argc == 3)
    {
        if ( !strcmp( argv[1], argv[2] ) )
        {
            fprintf( stderr, "reverse: input and output file must differ\n");
            exit(1);
        }

        *input = fopen( argv[1], "r" );
        checkFile( *input, argv[1] );
        *output = fopen( argv[2], "w" );
        checkFile( *output, argv[2] );
    }
    else if (argc == 2)
    {
        *input = fopen( argv[1], "r" );
        checkFile(*input, argv[1] );
        *output = stdout;
    }
    else if (argc == 1)
    {
        *input = stdin;
        *output = stdout;
    }
}

void
readAll(FILE * input, FILE * output)
{
    List list = (List)malloc(sizeof(List));
    checkMalloc( list );

    char * line = NULL;
    size_t linecap = 0;
    ssize_t linelen;
    while ( (linelen = getline(&line, &linecap, input) ) >= 0)
    {    
        char * text = (char *)malloc(sizeof(char) * (linelen + 1));
        checkMalloc( text );

        strcpy(  text, line );
        Insert( text, list, list );
    }
    
   PtrToNode cursor = list->Next; 
    while ( cursor )
    {
        fprintf( output, "%s", cursor->Element );
        free( cursor->Element ); 
        cursor = cursor->Next;
    }
    MakeEmpty( list );
}

int main(int argc, char *argv[], char *envp[])
{
    FILE * input;
    FILE * output;
    getInOut( &input, &output, argc , argv);
    /*
    input = fopen("in.txt", "r");
    output = fopen("out.txt", "w");
    */
    readAll(input, output);

    fflush(stdout);
    
    if (argc > 1)
        fclose(input);
    if (argc == 3)
        fclose(output);
    return 0;
}
