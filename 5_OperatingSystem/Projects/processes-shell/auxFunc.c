#include <string.h>
#include <stdlib.h>
// compute the number of arguments containing the last NULL
int
length_argv( char ** argv )
{
    int i = 0;
    for ( ; argv[i]; i++ )
        ;
    return i;
}

// compute the number of special symbol in arguments
int
get_symbol_num( char **argv, char *seq )
{
    int count = 0;
    for (int i = 0; argv[i]; i++)
    {
        if ( strcmp( argv[i], seq ) == 0 )
            count++;
    }
    return count;
}

// free dynamic memory
void
free_argv( char **argv )
{
    for (int i = 0; argv[i]; i++)
    {
        free(argv[i]);
        argv[i] = NULL;
    }
    argv = NULL;
}