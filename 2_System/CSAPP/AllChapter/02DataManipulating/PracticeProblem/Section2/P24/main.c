/*************************************************************************
 @Author: XieXun
 @Created Time : Fri 27 Nov 19:11:09 2020
 @File Name: main.c
 @Description:
 ************************************************************************/

#include <stdio.h>

int main()
{
    //          Hex                     Unsigned            Two's complement
    //  Original    Truncated   Original    Truncated   Original    Truncated
    //      1           1           1           1            1          1
    //      3           3           3           3            3          3
    //      5           5           5           5            5          5
    //      C(1100)     4           12          4            -4         -4
    //      E(1110)     6           14          6            -2         -2
    printf("//          Hex                     Unsigned            Two's complement\n"
            "Original    Truncated   Original    Truncated   Original    Truncated\n"
            "    1           1           1           1            1          1\n"
            "    3           3           3           3            3          3\n"
            "    5           5           5           5            5          5\n"
            "    C(1100)     4           12          4            -4         -4\n"
            "    E(1110)     6           14          6            -2         -2\n");
}
