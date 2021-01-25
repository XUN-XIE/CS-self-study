//
//  main.cpp
//  12.5
//
//  Created by 谢逊 on 2020/1/18.
//  Copyright © 2020 谢逊. All rights reserved.
//
#include "string01.hpp"

const int Arsize = 10;
const int Maxlen = 81;

int main()
{
    String name;
    cout << "Hi, what's your name?\n>>";
    cin >> name;
    
    cout << ", please enter up to " << Arsize << " short sayngs <empty line to quit>:\n";
    String sayings[Arsize];
    char temp[Maxlen];
    int i;
    for (i = 0; i < Arsize; i++)
    {
        cout << i + 1 << ": ";
        cin.get(temp, Maxlen);
        while (cin && cin.get() != '\n')
            continue;
        if (!cin || temp[0] == '\0')
            break;
        else
            sayings[i] = temp;
    }
    int total = i;
    
    if (total > 0)
    {
        cout << "Here are your sayings:\n";
        for (i = 0; i < total; i++)
            cout << sayings[i][0] << ": " << sayings[i] << endl;
        
        int shortest = 0;
        int first = 0;
        for (i = 1; i < total; i++)
        {
            if ( sayings[i].length() < sayings[shortest].length())
                shortest = i;
            if (sayings[i] < sayings[first])
                first = 1;
        }
        cout << "Shortest sayings:\n" << sayings[shortest] << endl;
        cout << "First alphabetically:\n" << sayings[first] << endl;
        cout << "This program used " << String::Howmany() << " String objects. Bye.\n";
    }
    else
        cout << "No input! Bye.\n";
    return 0;
}
