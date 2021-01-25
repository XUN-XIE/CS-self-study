//
//  main.cpp
//  4.21
//
//  Created by 谢逊 on 2020/1/12.
//  Copyright © 2020 谢逊. All rights reserved.
//

#include <iostream>

struct inflatable
{
    char name[20];
    float volume;
    double price;
};

int main()
{
    using namespace std;
    inflatable * ps = new inflatable;
    cout << "Enter name of infaltable item: ";
    cin.get(ps->name, 20);
    cout << "Enter volume iin cubic feet: ";
    cin >> (*ps).volume;
    cout << "Enter priice: $:";
    cin >> ps->price;
    cout << "Name:" << (*ps).name << endl;
    cout << "Volume: $" << ps->price << endl;
    delete ps;
    
    return 0;
}
