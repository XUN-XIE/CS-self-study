//
//  my.cpp
//  Chapter8
//
//  Created by 谢逊 on 2020/1/14.
//  Copyright © 2020 谢逊. All rights reserved.
//

#include "my.hpp"
#include "std_lib_facilities.h"
#include <iostream>

void print_foo(int foo)
{
    cout << foo;
}

void print(int i)
{
    cout << i;
}

//int main()
//{
//    int foo = 7;
//    print_foo(foo);
//}

void swap_v(int a, int b)
{
    int temp = a;
    a = b;
    b = temp;
}

void swap_r(int& a, int& b)
{
    int temp = a;
    a = b;
    b = temp;
}

//void swap_cr(const int& a, const int& b)
//{
//    int temp = a;
//    a = b;
//    b = temp;
//}
