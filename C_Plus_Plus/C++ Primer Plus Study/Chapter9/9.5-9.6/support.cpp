//
//  support.cpp
//  Chapter9
//
//  Created by 谢逊 on 2020/1/16.
//  Copyright © 2020 谢逊. All rights reserved.
//


#include <iostream>

extern double warming;

void update(double dt);
void local();

void update(double dt)
{
    using std::cout;

    extern double warming;
    warming += dt;
    cout << "Updating global warming to " << warming;
    cout << " degrees.\n";
}

void local()
{
    using std::cout;

    double warming = 0.8;
    
    cout << "Local warminig = " << warming << " degrees.\n";
    cout << "But global warming" << ::warming;
    cout << " degrees.\n";
}
