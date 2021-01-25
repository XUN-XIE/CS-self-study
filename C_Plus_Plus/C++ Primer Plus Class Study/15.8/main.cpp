//
//  main.cpp
//  15.8
//
//  Created by 谢逊 on 2020/1/22.
//  Copyright © 2020 谢逊. All rights reserved.
//

#include <iostream>
#include <cfloat>

using namespace std;

bool hmean(double a, double b);

int main()
{
    double x, y, z;
    
    cout << "Enter two numbers: ";
    while (cin >> x >> y)
    {
        try
        {
            z = hmean(x, y);
        }
        catch (const char * s)
        {
            cout << s << endl;
            cout << "Enter new pair of numbers: ";
            continue;
        }
        cout << "Harmonic mean of " << x << " and " << y << " is " << z << endl;
        cout << "Enter next set of numbers <q to quit>: ";
    }
    cout << "Bye!\n";
    return 0;
}

bool hmean(double a, double b)
{
    if ( a == -b )
        throw "bad hmean() arguments:  = -b not allowed";
    return 2.0 * a * b / (a + b);
}
