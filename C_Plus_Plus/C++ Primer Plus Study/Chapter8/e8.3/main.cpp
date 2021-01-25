//
//  main.cpp
//  e8.3
//
//  Created by 谢逊 on 2020/1/15.
//  Copyright © 2020 谢逊. All rights reserved.
//

#include <iostream>
#include <string>

using namespace std;

void upper(string & str);



int main()
{
    cout << int('a') << endl << int('A') << endl;
    
    string str;
    cout << "Enter: ";
    cin >> str;
    upper(str);
    cout << str;
    
    return 0;
}

void upper(string & str)
{
    for (int i = 0; i < str.size(); i++)
        str[i] = char(int(str[i]) - 32);
}
