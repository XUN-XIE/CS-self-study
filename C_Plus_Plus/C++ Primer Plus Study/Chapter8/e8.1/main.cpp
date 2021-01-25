//
//  main.cpp
//  e8.1
//
//  Created by 谢逊 on 2020/1/15.
//  Copyright © 2020 谢逊. All rights reserved.
//

#include <iostream>

void print_str(char * str, int n = 0);

using namespace std;

int main()
{
    char str[10] = "asdfg";
    
    print_str(str, 1);
    
    return 0;
}

void print_str(char * str, int n)
{
    cout << str << endl;
}
