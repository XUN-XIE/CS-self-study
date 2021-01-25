//
//  main.cpp
//  Drill8
//
//  Created by 谢逊 on 2020/1/14.
//  Copyright © 2020 谢逊. All rights reserved.
//

#include <iostream>

#include "my.hpp"


int main()
{
    int foo = 7;
    print_foo(foo);
    
    int i = 99;
    print(i);
    
    cout << endl;
    
    int x = 7;
    int y = 9;
    swap_v(x, y);
    print(x);
    print(y);
    cout << endl;
    
    swap_r(x, y);
    print(x);
    print(y);
    cout << endl;
    
    const int cx = 7;
    const int cy = 9;
    swap_v(cx, cy);
    print(cx);
    print(cy);
    cout << endl;
    
//    swap_r(cx, cy);
//    print(cx);
//    print(cy);
//    cout << endl;
    
    double dx = 7.7;
    double dy = 9.9;
    swap_v(dx, dy);
    print(dx);
    print(dy);
    cout << endl;
    
//    swap_r(dx, dy);
//    print(dx);
//    print(dy);
//    cout << endl;
}
