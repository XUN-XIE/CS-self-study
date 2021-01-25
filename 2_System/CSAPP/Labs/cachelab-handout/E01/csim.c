/*************************************************************************
 @Author: XieXun
 @Created Time : Tue 22 Dec 15:02:54 2020
 @File Name: csim.c
 @Description:
 ************************************************************************/

 #include "cachelab.h"
#include "func.h"

int main( int argc, char *argv[] )
{
    CommandInfo * Info = readPar( argv );
    // printf("-s = %d, -E = %d, -b = %d, -t = %s\n", Info->s, Info->E, Info->b, Info->filename); CountAll * count = MainLogic( Info );
    CountAll * count = MainLogic( Info );
    // printf("-------");
    // fflush(stdout);
    free(Info);    
    printSummary(count->H, count->M, count->E);
    free(count);
    return 0;
}
