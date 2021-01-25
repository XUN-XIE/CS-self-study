//
//  stock00.hpp
//  chapter10
//
//  Created by 谢逊 on 2020/1/14.
//  Copyright © 2020 谢逊. All rights reserved.
//

#ifndef stock00_hpp
#define stock00_hpp

#include <iostream>
#include <stdio.h>

#include <string>


class Stock
{
    
private:
    std::string company;
    long shares;
    double share_val;
    double total_val;
    void set_tot() { total_val = shares * share_val; }
    
public:
    void acquire(const std::string & co, long n, double pr);
    void buy(long num, double price);
    void sell(long num, double price);
    void update(double price);
    void show();
};


#endif /* stock00_hpp */
