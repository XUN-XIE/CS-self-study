/*************************************************************************
 @Author: XieXun
 @Created Time : Sat  5 Dec 10:36:03 2020
 @File Name: main.c
 @Description:
 ************************************************************************/

#include <stdio.h>

struct {
  int    *a;
  float  b;
  char   c;
  short  d;
  long   e;
  double f;
  int g;
  char   *h;
} rec;

int main()
{
    printf("ProblemA:\n");
    printf("a   b   c   d   e   f   g   h\n");
    printf("0   8   12  16  24  32  40  48\n");
    printf("8   4   1   2   8   8   4   8")
    printf("\nProblem B: total size = 40\n");
    printf("c,d,b,g,a,e,f,h\n");
}
