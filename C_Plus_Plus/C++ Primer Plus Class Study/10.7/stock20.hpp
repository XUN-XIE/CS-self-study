//
//  stock20.hpp
//  10.7
//
//  Created by 谢逊 on 2020/1/16.
//  Copyright © 2020 谢逊. All rights reserved.
//

#ifndef stock20_hpp
#define stock20_hpp

#include <stdio.h>

#include <string>
using namespace std;

class Stock
{
    
private:
    std::string company;
    long shares;
    double share_val;
    double total_val;
    void set_tot() { total_val = shares * share_val; }
    
public:
    Stock();
    Stock(const string & co, long n = 0, double pr = 0.0);
    ~Stock();
    void buy(long num, double price);
    void sell(long num, double price);
    void update(double price);
    void show() const;
    const Stock & topval(const Stock & s) const;
};

#endif /* stock20_hpp */
