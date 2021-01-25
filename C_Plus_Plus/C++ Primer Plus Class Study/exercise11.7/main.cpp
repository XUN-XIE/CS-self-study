//
//  main.cpp
//  exercise11.7
//
//  Created by 谢逊 on 2020/1/18.
//  Copyright © 2020 谢逊. All rights reserved.
//

#include <iostream>
#include "complex0.hpp"

int main()
{
    complex a(3.0, 4.0);
    complex c;
    
    cout << "Enter a complex number (q to quit):\n";
    while (cin >> c)
    {
        cout << "c s " << c << '\n';
        cout << "complex congjugate iis " << ~c << '\n';
        cout << "a is " << a << '\n';
        cout << "a + c is " << a + c << '\n';
        cout << "a - c is " << a - c << '\n';
        cout << "a * c is " << a * c << '\n';
        cout << "2 * c is " << 2 * c << '\n';
        cout << "Enter a complex number (q to quit):\n";
    }
    cout << "Done!\n";
    
    return 0;
}
