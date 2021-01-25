//
//  main.cpp
//  8
//
//  Created by 谢逊 on 2020/1/12.
//  Copyright © 2020 谢逊. All rights reserved.
//

#include <iostream>
#include <cstring>

using namespace std;

struct info
{
    string name;
    double diameter;
    double weight;
};

int main()
{
    info * str = new info;
    
    cin >> str->weight;
    cout << "wight is " << str->weight << endl;
    
    cin.get();
    getline(cin, str->name);
    cout << "name is " << str->name << endl;
    
}
