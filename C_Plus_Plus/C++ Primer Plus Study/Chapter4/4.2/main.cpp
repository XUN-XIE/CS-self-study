//
//  main.cpp
//  4.2
//
//  Created by 谢逊 on 2020/1/11.
//  Copyright © 2020 谢逊. All rights reserved.
//

#include <iostream>
#include <cstring>

int main()
{
    using namespace std;
    const int Size = 15;
    char name1[Size];
    char name2[Size] = "C++owboy";
    
    cout << "Howdy! I'm " << name2;
    cout << "! What's your name?\n";
    
    cin >> name1;
    
    cout << "Well, " << name1 << ", your name has ";
    cout << strlen(name1) << " letters and is stored\n";
    cout << "Your initial is  " << name1[0] << ".\n";
    name2[3] = '\0';
    cout << "Here are the first 3 characters of my name: ";
    cout << name2 << endl;
    
    return 0;
}
