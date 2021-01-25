//
//  main.cpp
//  12.7
//
//  Created by 谢逊 on 2020/1/18.
//  Copyright © 2020 谢逊. All rights reserved.
//

#include "string2.hpp"

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
        
        
        String * shortest = &sayings[0];
        String * first = &sayings[0];
        for (i = 1; i < total; i++)
        {
            if ( sayings[i].length() < shortest->length())
                shortest = &sayings[i];
            if (sayings[i] < *first)
                first = &sayings[i];
        }
        cout << "Shortest sayings:\n" << *shortest << endl;
        cout << "First alphabetically:\n" << *first << endl;
        
        srand(time(0));
        int choice = rand();
        String * favorite = new String(sayings[choice]);
        cout << "My favorite saying:\n" << *favorite << endl;
        delete favorite;
    }
    else
        cout << "Not much to say, eh?\n";
    return 0;
}
