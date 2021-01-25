#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

// error message
char error_message[30] = "An error has occurred\n";

/*
idea flow：

sequential flow:
    read line from two mode --> parseLine
                ^
                |
                |
    handle parallel --> general_case
                ^
                |
                |
    handle path checking --> call_execv
                ^
                |
                |
    handle redirection --> redirection case


parallel flow:  
three built-in function

path function
*/

// global variable —— path
char **path = NULL;

//---------------------------- main framework functions-----------------------
// used to parse every line from interactive mode or batch mode
char **
parseLine( FILE * fp , int count , int mode );

void
redirection_case( char **argv, char * absolute );

// 用于调用 execv 的函数
// 因为需要在 可执行文件前加上 全局变量 path
// 所以单独写出来
void
call_execv( char **argv );

// wrapper function to handle the failed case when calling execv function
void
handle_execv_error( int status );

// handle redirection case
void
redirection_case( char **argv, char * absolute );

// intermediate function to process the path
void
call_execv( char **argv );

// function to process non-built-in command
void 
general_case( char **argv );

// function to differentiate two different mode
void
mainFrame( FILE * fp, int mode);

//------------------------------- built-in functions ------------------------
// function to simulate command 'cd'
int
change_directory( char ** argv , int len );

// function to change environment variable —— path
void
path_case( char ** argv, int len );

// -------------------------------auxiliary functions-------------------------------
// compute the number of arguments containing the last NULL
int
length_argv( char **argv);

// compute the number of special symbol in arguments
int
get_symbol_num( char **argv, char *seq );

// compute the number of special symbol in arguments
int
get_symbol_num( char **argv, char *seq );

// free dynamic memory
void
free_argv( char **argv );