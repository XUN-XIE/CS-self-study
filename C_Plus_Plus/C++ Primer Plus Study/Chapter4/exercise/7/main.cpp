//
//  main.cpp
//  7
//
//  Created by 谢逊 on 2020/1/12.
//  Copyright © 2020 谢逊. All rights reserved.
//

#include <iostream>
#include <string>
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
    info pissa;
    
    cout << "What's the name of company? ";
    getline(cin, pissa.name);
    
    cout << pissa.name << " and " << pissa.name.size() << endl;
    
    return 0;
    
}
