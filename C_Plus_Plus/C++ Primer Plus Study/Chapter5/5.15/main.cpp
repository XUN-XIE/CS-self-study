//
//  main.cpp
//  5.15
//
//  Created by 谢逊 on 2020/1/14.
//  Copyright © 2020 谢逊. All rights reserved.
//

#include <iostream>
using namespace std;

int main()
{
    int n;
    
    cout << "Enter number in the range 1-10 to find ";
    cout << "my favorite number\n";
    
    do {
            cin >> n;
        } while (n != 7);
        cout << "Yes, 7 is my faborite.\n";
        
    return 0;
}
