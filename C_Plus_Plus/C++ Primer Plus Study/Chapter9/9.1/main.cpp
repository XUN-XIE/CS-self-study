//
//  main.cpp
//  9.1
//
//  Created by 谢逊 on 2020/1/14.
//  Copyright © 2020 谢逊. All rights reserved.
//

#include <iostream>
#include "coor.hpp"

using namespace std;

int main()
{
    rect rplace;
    polar pplace;
    
    cout << "Enter the x and y values: ";
    
    while (cin >> rplace.x >> rplace.y)
    {
        pplace = rect_to_polar(rplace);
        show_polar(pplace);
        cout << "Next two numbers (q to quit): ";
    }
    cout << "Byes!\n";
    
    return 0;
}
