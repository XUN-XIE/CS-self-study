//
//  main.cpp
//  8.11
//
//  Created by 谢逊 on 2020/1/15.
//  Copyright © 2020 谢逊. All rights reserved.
//

#include <iostream>

template <class T>
void Swap(T & a, T & b);

int main()
{
    using namespace std;
    int i = 10;
    int j = 20;
    cout << "i, j = " << i << ", " << j << ".\n";
    Swap(i,j);
    cout << "Now i, j = " << i << ", " << j << ".\n";
    
    double x = 24.5;
    double y = 81.7;
    cout << "x, y = " << x << ", " << y << ".\n";
    Swap(i,j);
    cout << "Now x, y = " << x << ", " << y << ".\n";
    
    return 0;
}

template <class T>
void Swap(T & a, T & b)
{
    T temp;
    temp = a;
    a = b;
    b = temp;
}
