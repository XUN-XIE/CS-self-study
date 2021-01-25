//
//  main.cpp
//  6.11
//
//  Created by 谢逊 on 2020/1/14.
//  Copyright © 2020 谢逊. All rights reserved.
//

#include <iostream>

enum {red, orange, yellow, green, blue, violet, indigo};

int main()
{
    using namespace std;
    
    cout << "Enter color code (0-6): ";
    int code;
    cin >> code;
    
    while (code >= red && code <= indigo)
    {
        switch (code)
        {
            case red    : cout << "Her lips were red.\n"; break;
            case orange : cout << "orange.\n"; break;
            case yellow : cout << "yellow.\n";break;
            case green  : cout << "green.\n";break;
            case blue   : cout << "blue.\n";break;
            case violet : cout << "violet.\n";break;
            case indigo : cout << "indigo.\n";break;
        }
        
        cout << "Enter color code (0-6): ";
        cin >> code;
    }
    cout << "Bye\n";
    
    return 0;
}
