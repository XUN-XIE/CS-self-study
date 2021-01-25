#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

extern char **path;
extern char *error_message;
void call_error();

// function to simulate command 'cd'
int
change_directory( char **res , int len )
{
    // the number of argument is not one case
    // printf("fail to call command 'cd' for wrong number of arguments %d\n", len);
    if ( len != 2 )
        return 1;
    
    int returned = chdir( res[1] );

    // fail to call chdir case
    if ( returned == -1 )
    {
        // printf("fail to call chdir\n");
        return 1;
    }
    return 0;
}


// function to change environment variable —— path
void
path_case( char ** argv, int len )
{
    // // debug code 
    // for (int i = 0; argv[i]; i++)
    //         printf("|%s| ", argv[i]);
    //     printf("\n");
    if (path != NULL)
    {
        free(path);
        path = NULL;
    }

    if (len == 1)
        return;

    path = (char **)malloc(sizeof(char *) * len);
    free(argv[0]);
    argv[0] = NULL;
    for (int i = 0; i < len - 1; i++)
    {
        char *tmp = (char *)malloc(sizeof(char) * strlen(argv[i+1]));
        strcpy( tmp, argv[i+1] );
        free(argv[i+1]);
        path[i] = tmp;
    }

    path[len - 1] = NULL;


    /* // debug code
    for (int i = 0; path[i]; i++)
        printf("path update now = %s\n", path[i]);
        */
    // printf("----\n");
}