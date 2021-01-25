//
//  main.cpp
//  e7.1
//
//  Created by 谢逊 on 2020/1/15.
//  Copyright © 2020 谢逊. All rights reserved.
//

#include <iostream>
using namespace std;

void harmonic(double a, double b);

int main()
{
    double f;
    double s;
    
    while (cin >> f >> s && f != 0 && s != 0)
        harmonic(f, s);
    
    return 0;
}

void harmonic(double a, double b)
{
    double c = 1/(1/a + 1/b);
    
    cout << c << endl;
}
