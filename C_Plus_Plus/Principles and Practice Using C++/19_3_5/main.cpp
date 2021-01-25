//
//  main.cpp
//  19_3_5
//
//  Created by 谢逊 on 2020/1/23.
//  Copyright © 2020 谢逊. All rights reserved.
//

#include <iostream>

template <class T, int N>
struct array{
    T elem[N];
    
    T & operator[] (int n) { return elem[n]; }
    const T & operator[](int n) const { return elem[n]; }
    
    T * data() { return elem; }
    const T * data() const { return elem; }
    
    int size() const { return N; }
};

array<int, 256> gb;
array<double, 6> ad = {0.0, 1.1, 2.2, 3.3, 4.4, 5.5};
const int max = 1024;

void some_fct(int n);
void some_fct(int n)
{
    array<char, max> loc;
    
    array<char, max> loc2 = loc;
    
    loc = loc2;
}

int main()
{
    some_fct(10);
}
