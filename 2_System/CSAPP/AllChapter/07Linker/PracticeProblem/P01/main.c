/*************************************************************************
 @Author: XieXun
 @Created Time : Wed 23 Dec 08:39:27 2020
 @File Name: main.c
 @Description:
 ************************************************************************/

#include <stdio.h>

// every relocatable object file has symbol table
// symbol table do not contain local nonstatic program variables
//

int main()
{
    printf("Symbol  entry?  Type    modueldefined   Section\n");
    printf("buf     YES     extern  m.o             .data\n");
    printf("bufp0   YES     global  swap,o          .data\n");
    printf("bufp1   YES     global  swap.o          .bss\n");
    printf("swap    YES     global  swap.o          .text\n");
    printf("temp    NO      ——      ——              ——\n");
}
