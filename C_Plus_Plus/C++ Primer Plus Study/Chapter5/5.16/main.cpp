//
//  main.cpp
//  5.16
//
//  Created by 谢逊 on 2020/1/14.
//  Copyright © 2020 谢逊. All rights reserved.
//

#include <iostream>

int main()
{
    using namespace std;
    char ch;
    int count = 0;
    
    cout << "Enter characters; enter # o quit:\n";
    cin.get(ch);
    
    while (ch != '#')
    {
        cout << ch;
        ++count;
        cin.get(ch);
    }
    
    cout << endl << count << " charaters read\n";
    
    return 0;
}
