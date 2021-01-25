/************************************************************************
 @Author: XieXun
 @Created Time : Wed  2 Dec 19:53:10 2020
 @File Name: mstore.c
 @Description:
 ************************************************************************/

long mult2(long, long);

void multstore(long x, long y, long *dest)
{
    long t = mult2(x, y);
    *dest = t;
}
