//
//  main.cpp
//  8.1
//
//  Created by 谢逊 on 2020/1/15.
//  Copyright © 2020 谢逊. All rights reserved.
//

#include <iostream>

inline double square(double x) {return x * x;}

int main()
{
    using namespace std;
    double a, b;
    double c = 13.0;
    
    a = square(5.0);
    b = square(4.5 + 7.5);
    cout << b;
}
