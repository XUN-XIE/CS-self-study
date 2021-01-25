/*************************************************************************
 @Author: XieXun
 @Created Time : Mon  4 Jan 10:37:58 2021
 @File Name: wish.c
 @Description:
 ************************************************************************/
#include "wish.h"

void
call_error()
{
    write(STDERR_FILENO, error_message, strlen(error_message));
    fflush(stdout);
    exit(1);
}

// wrapper function to handle the failed case when calling execv function
void
handle_execv_error( int status )
{
    if (status == -1)
    {
        write(STDERR_FILENO, error_message, strlen(error_message));
        fflush(stdout);
    }
}

// handle redirection case
void
redirection_case( char **argv, char * absolute )
{
    
    int index = 0;
    for (; strcmp( argv[index], ">" ); index++)
        ;
    // multiple file error
    int j = index + 1;
    for ( ; argv[j]; j++)
        ;
    
    // no output file case
    if ( j - index != 2 )
        call_error();

    FILE * output = fopen( argv[index + 1], "w" );
    if (output == NULL)
    {
        call_error();
    }

    int descriptor = fileno( output );
    int dupStatus = dup2( descriptor, 1 );
    if (dupStatus == -1)
        call_error();

    argv[index] = NULL;
    handle_execv_error(execv( absolute, argv ));
}

// intermediate function to process the path
void
call_execv( char **argv )
{
    if ( path == NULL )
        call_error();

    int redirection = get_symbol_num( argv, ">");
    // multiple redirection case
    if (redirection > 1)
        call_error();


    int no_access = 1;
    for ( int i = 0; path[i] != NULL; i++)
    {
        
        int length = strlen(path[i]) + strlen(argv[0]);
        char * absolute = (char *)malloc(sizeof(char) * (length + 2));
        strcpy( absolute, path[i] );
        strcat( absolute, "/");
        strcat( absolute, argv[0] );
        
        int acc = access( absolute, X_OK );

        // check accessibility
        if ( acc == -1 )
            continue;

        no_access = 0;
        // redirection case
        if ( redirection )
            redirection_case( argv, absolute );
        else
            handle_execv_error( execv( absolute, argv ) );
            
        free(absolute);
        absolute = NULL;
    }

    if (no_access)
    {
        call_error();
    }
}

// function to process non-built-in command
void 
general_case( char **argv )
{
    int pid = -1; 
    
    int parallel = get_symbol_num( argv, "&" );
    // printf("parallel = %d\n", parallel);
    int index = 0;
    for (int i = 0; i < parallel + 1; i++)
    {
        // 遍历到结尾，跳出循环
        if ( argv[index] == NULL )
            break;   

        pid = fork();
        
        // argument length
        int length = 0;
        for ( ; argv[index] != NULL && strcmp( argv[index], "&") ; index++)
            length++;

        
        // // multiple redirection case
        // if (redirection > 1)
        //     call_error();

        char ** child_arg = (char **)malloc(sizeof(char *) * length + 1);
        for (int j = 0; j < length; j++)
        {
            char *tmp = (char *)malloc(sizeof(char) * strlen(argv[index - length + j]) + 1);
            strcpy(tmp, argv[ index - length + j ]);
            free( argv[ index - length + j ] );
            argv[ index - length + j ] = NULL;
            child_arg[j] = tmp;
        }
        child_arg[length] = NULL;   

        if ( argv[index] )
            index++;
        
        

        if (pid == 0)
        {
            call_execv( child_arg );
            exit(0);
        }
    }
    // parent process
    // 阻塞全部子进程！
    if (pid > 0)
        while( wait(NULL) != -1 )
            ;
    
}

// function to differentiate two different mode
void
mainFrame( FILE * fp, int mode )
{    
    int count = -1;
    while (1)
    {
        count++;
        // print prompt
        if (mode == 1)
            printf("wish>");

        char **argv = parseLine( fp , count, mode );

        // // debug code
        // for (int i = 0; argv[i]; i++)
        //     printf("|%s| ", argv[i]);
        // printf("\n");

        int length = length_argv( argv );
    
        // no input case
        if ( length == 0 )
            continue;

        

        // three built-in case
        // 1. exit case
        if ( strcmp( argv[0], "exit") == 0 )
        {
            if (length > 1)
            {
                write(STDERR_FILENO, error_message, strlen(error_message));
                fflush(stdout);
            }
            exit(0);
        }
        // 2. cd case
        else if ( strcmp( argv[0], "cd" ) == 0 )
        {
            int result = change_directory( argv, length );
            if ( result )
            {
                write(STDERR_FILENO, error_message, strlen(error_message));
                fflush(stdout);
                continue;
            }
        }
        // 3. path case
        else if ( strcmp( argv[0], "path" ) == 0 )
            path_case( argv, length );
        // 4. general case
        else
        {
            general_case( argv );
        }
        if ( argv )
            free_argv( argv );
    }
}


int main( int argc, char *argv[], char *envp[] )
{
    path = (char **)malloc(sizeof(char *));
    char bin[5] = "/bin";
    path[0] = (char *)malloc(sizeof(char) * 5);
    strcpy( path[0], bin);
    // batch mode
    if ( argc == 2 )
    {
        FILE * fp = fopen( argv[1], "r" );

        // fail to open file case
        if (fp == NULL)
            call_error();

        mainFrame( fp, 0 );
    }
    // too many file in batch mode case
    else if (argc > 2)
        call_error();
    // interactive mode
    else
        mainFrame( stdin, 1 ); 
    
    if (path)
    {
        free(path[0]);
        path[0] = NULL;
        free(path);
        path = NULL;
    }
}
