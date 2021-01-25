//
//  main.cpp
//  4.4
//
//  Created by 谢逊 on 2020/1/11.
//  Copyright © 2020 谢逊. All rights reserved.
//

#include <iostream>

int main()
{
    using namespace std;
    
    const int Size = 20;
    char name[Size];
    char dessert[Size];
    
    cin.getline(name, 20);
    cin.getline(dessert, 20);
    cout << name << endl << dessert << endl;
    
    return 0;
}
