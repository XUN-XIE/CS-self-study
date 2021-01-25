//
//  main.cpp
//  7.9
//
//  Created by 谢逊 on 2020/1/15.
//  Copyright © 2020 谢逊. All rights reserved.
//

#include <iostream>

int c_in_str(const char * str, char ch);

using namespace std;

int main()
{
    char mmm[15] = "minimun";
    
    char * wail = "ululate";
    
    int ms = c_in_str(mmm, 'm');
    int us = c_in_str(wail, 'u');
    
    cout << ms << " m characters in " << mmm << endl;
    cout << us << " u characters in " << wail << endl;
    
    return 0;
}

int c_in_str(const char * str, char ch)
{
    int count = 0;
    
    while (*str)
    {
        if (*str == ch)
            count++;
        str++;
    }
    
    return count;
}
