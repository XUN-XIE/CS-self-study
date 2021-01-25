/*************************************************************************
 @Author: XieXun
 @Created Time : Thu 24 Dec 09:49:40 2020
 @File Name: main.c
 @Description:
 ************************************************************************/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>

unsigned int
wakeup( unsigned int secs )
{
    unsigned int elapsed = sleep(secs);
    printf("Woke up at %ud %s\n",  secs - elapsed + 1, (secs - elapsed + 1) < 2 ? "sec" : "secs" );

    return elapsed;
}

void
sigint_handler( int sig )
{
    printf("Caught SIGINT\n");
}

int main(int argc, char *argv[], char *envp[])
{
       int time = atoi( argv[1] );
       
       if (signal(SIGINT, sigint_handler) == SIG_ERR)
           printf("signal error\n");

       wakeup(time);
}
