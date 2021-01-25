/*************************************************************************
 @Author: XieXun
 @Created Time : Wed 23 Dec 19:37:35 2020
 @File Name: main.c
 @Description:
 ************************************************************************/

#include <stdio.h>
#include <unistd.h>

unsigned int
wakeup( unsigned int secs )
{
    unsigned int elapsed = sleep(secs);
    printf("Woke up at %ud %s\n",  secs - elapsed + 1, (secs - elapsed + 1) < 2 ? "sec" : "secs" );

    return elapsed;
}

int main()
{

}
