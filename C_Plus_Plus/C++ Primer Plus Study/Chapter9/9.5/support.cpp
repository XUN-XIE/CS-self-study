//
//  support.cpp
//  Chapter9
//
//  Created by 谢逊 on 2020/1/16.
//  Copyright © 2020 谢逊. All rights reserved.
//


#include "support.hpp"

void update(double dt)
{
    

    extern double warming;
    warming += dt;
    std::cout << "Updating global warming to " << warming;
    std::cout << " degrees.\n";
}

void local()
{
    

    double warming = 0.8;
    
    std::cout << "Local warminig = " << warming << " degrees.\n";
    std::cout << "But global warming" << ::warming;
    std::cout << " degrees.\n";
}
