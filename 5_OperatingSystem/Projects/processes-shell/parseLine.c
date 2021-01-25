#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "List.h"

extern char *error_message;

struct Node {
    ElementType Element;
    Position Next;
};

void call_error();

const char * specialSymbol = ">&";

// insert argument into List
static void
add_to_argv( char * token, List L, char seq )
{
    char * unitT = (char *)malloc(sizeof(char) * ( strlen(token) + 1)); 
    strcpy( unitT, token );
    // argv[(*countArg)++] = unitT;
    Insert( unitT, L, L );
    char * addSeq = (char *)malloc(sizeof(char) * 2);
    addSeq[0] = seq;
    addSeq[1] = '\0';
    // argv[(*countArg)++] = addSeq;
    Insert( addSeq, L, L );
}

// prevent parallel and redirection symbol is combined with other words
static void
process_text_unit( char * text, List L, char seq)
{
    char seqs[2];
    seqs[0] = seq;
    char *token = strtok( text, seqs );

    while (token)
    {
        add_to_argv( token, L , seq );

        token = strtok( NULL, seqs );
    }
    // 多计数了一个
    // free(argv[--(*countArg)]);
    // argv[*countArg] = NULL;
    
    Delete( seqs, L );
}

// private function to get the number of special symbol in text
static int
get_special_num( char * text )
{
    int count = 0;
    for (int i = 0; text[i]; i++)
        if (text[i] == '>' || text[i] == '&')
            count++;
    return count;
}

// used to parse every line from interactive mode or batch mode
char **
parseLine( FILE * fp , int count, int mode )
{
    char *line = NULL;
    size_t linecap = 0;
    ssize_t linelen;
    
    linelen = getline( &line, &linecap, fp );

    
    // 处理 batch mode
    if (linelen <= 0 && mode == 0)
    {
        // printf("------------\n");
        // fflush(stdout);
        // 空文件 batch mode
        // printf("come in\n");
        if (count == 0)
            call_error();
        // batch mode 正常结尾
        else
            exit(0);
    }
    
    // 修改最后键入的换行符为空格，使得 strtok 函数可以分割每个 argument
    line[linelen - 1] = ' ';

    // int redirection = 0;
    // int parallel = 0;
    int countArg = 0;
    int size_limit = 3;
    // char **argv = (char **)malloc(sizeof(char *) * 2);

    // 用链表临时存储 text unit，方便内存管理
    List L = (List)malloc(sizeof(struct Node));
// ----------------------------- 必须初始化，否则 Next 会被初始化为垃圾值！------------------------
    L->Next = NULL;
    // printf("------\n");
    // fflush(stdout);
    char *token = strtok( line, " " );
    while (token)
    {
        // size_t specialNum = strspn( token, specialSymbol );
        int specialNum = get_special_num( token );
        // printf("%s\t%s\n", token, specialSymbol);

        // printf("special = %d\n", specialNum);

        // no special symbol case
        if ( !specialNum || ( strlen( token ) == 1 ) )
        {
            char * text = (char *)malloc(sizeof(char) * ( strlen(token) + 1)); 
            strcpy( text, token );
            // 倒序插入
            Insert( text, L, L );
        }
        else
        {
            if ( strchr(token, '&') )
                process_text_unit( token, L, '&' );
            else if (strchr( token, '>' ))
                process_text_unit( token, L, '>' );
        }
        token = strtok( NULL, " " );
    }
    
    int length = ListSize( L );
    // printList(L);

    char **argv = (char **)malloc(sizeof(char *) * length + 1);
    Position cursor = L->Next;

    for (int i = length - 1; i >= 0; i--)
    {
        char *tmp = (char *)malloc(sizeof(char) * strlen(cursor->Element));
        strcpy( tmp, cursor->Element );
        free(cursor->Element);
        cursor->Element = NULL;
        argv[i] = tmp;
        cursor = cursor->Next;
    }
    // printf("------\n");
    // fflush(stdout);
    MakeEmpty( L );
    argv[length] = NULL;
    return argv;
}