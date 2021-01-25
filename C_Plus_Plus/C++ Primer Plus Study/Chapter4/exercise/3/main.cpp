//
//  main.cpp
//  3
//
//  Created by 谢逊 on 2020/1/12.
//  Copyright © 2020 谢逊. All rights reserved.
//

#include <iostream>
#include <cstring>

using namespace std;

int main()
{
    char first[20];
    char last[20];
    
    cout << "Enter your first name: ";
    cin >> first;
    cout << "Enter your last name: ";
    cin >> last;
    
    cout << "Here's the information in a single string: " << first << ", " << last << endl;
    
    return 0;
}
