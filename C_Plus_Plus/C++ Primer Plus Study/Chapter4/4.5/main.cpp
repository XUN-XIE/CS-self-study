//
//  main.cpp
//  4.5
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
    
    cin.get(name, 20).get();
    cin.get(dessert, 20).get();
    cout << name << endl << dessert << endl;
    
    return 0;
}
