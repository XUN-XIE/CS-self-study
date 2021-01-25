/*************************************************************************
 @Author: XieXun
 @Created Time : Thu 31 Dec 16:00:07 2020
 @File Name: reverse.c
 @Description:
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void
checkFile( FILE * stream )
{
    if ( !stream )
    {
        printf("can't open file\n");
        fflush(stdout);

        exit( 1 );
    }
}

void
getInOut( FILE ** input, FILE ** output, int argc, char *argv[] )
{
    if (argc > 3)
    {
        exit(1);
    }
    // printf("arguments = %d\n %s %s\n", argc, argv[1], argv[2]);
    if (argc == 3)
    {
        *input = fopen( argv[1], "r" );
        checkFile(*input);
        *output = fopen( argv[2], "w" );
        checkFile(*output);
        printf("infile outfile\n");
    }
    else if (argc == 2)
    {
        *input = fopen( argv[1], "r" );
        checkFile(*input);
        *output = stdout;
        printf("only infile\n");
    }
    else if (argc == 1)
    {
        *input = stdin;
        *output = stdout;
        printf("no files\n");
    }
}

typedef struct {
    char * text;
    unsigned len;
} Line;

void
readAll(FILE * input, FILE * output)
{
    unsigned init_size = 10;
    Line * LineArr = (Line *)malloc(sizeof(Line) * init_size);
    int countLine = 0;
    size_t size_limit = init_size;

    char * line = NULL;
    size_t linecap = 0;
    ssize_t linelen;
    while ( (linelen = getline(&line, &linecap, input) ) >= 0)
    {    
        LineArr[countLine].text = (char *)malloc(sizeof(char) * (linecap + 1));
        if (LineArr[countLine].text == NULL)
        {
            printf("countLine = %d\n", countLine);
            printf("\033[41mmalloc failed\033[0m\n");
            exit(1);
        }
        strncpy(  LineArr[countLine].text, line, linelen);
        LineArr[countLine].text[linelen] = '\0';
        LineArr[countLine].len = linelen + 1;

        printf("countLine = %d\n", countLine);
        printf("line address = %x\n", line);
        printf("line = %s\n", line);

        countLine++;

        if (countLine >= size_limit)
        {
            size_limit *= 2;
            LineArr = (Line *)realloc(LineArr, size_limit);
            if (LineArr == NULL)
            {
                printf("realloc failed\n");
                fflush(stdout);
                exit(1);
            }
        }
    }

    for (int i = 0; i < 10; i++)
        printf("%x\n", (LineArr+i));
    for (int i = countLine - 1; i >= 0; i--)
    {
        printf("i = %d\n", i);
        printf("text address = %x\n", LineArr[i].text);
        printf("text = |%s|\n", LineArr[i].text);
        fflush(stdout);
        fwrite( LineArr[i].text, LineArr[i].len, 1, output);
        free(LineArr[i].text);
    }
}

int main(int argc, char *argv[], char *envp[])
{
    FILE * input;
    FILE * output;
    // getInOut( &input, &output, argc , argv);
    input = fopen("reverse.c", "r");
    output = fopen("out.txt", "w");

    readAll(input, output);

    fflush(stdout);
    
    if (argc > 1)
        fclose(input);
    if (argc == 3)
        fclose(output);
}
