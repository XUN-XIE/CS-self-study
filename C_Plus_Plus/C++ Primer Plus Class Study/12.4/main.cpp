//
//  main.cpp
//  12.4
//
//  Created by 谢逊 on 2020/1/18.
//  Copyright © 2020 谢逊. All rights reserved.
//

#include <iostream>
#include "string1.hpp"

const int Arsize = 10;
const int Maxlen = 81;

int main()
{
    String name;
    cout << "Hi, what's your name?\n>>";
    cin >> name;
    
    cout << ", please enter up to " << Arsize << " short sayngs <empty line to quit>:\n";
    String sayngs[Arsize];
    char temp[Maxlen];
    for (int i = 0; i < Arsize; i++)
    {
        cout << i + 1 << ": ";
        
    }
}
