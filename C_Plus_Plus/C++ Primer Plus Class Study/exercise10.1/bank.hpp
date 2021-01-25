//
//  bank.hpp
//  exercise10.1
//
//  Created by 谢逊 on 2020/1/16.
//  Copyright © 2020 谢逊. All rights reserved.
//

#ifndef bank_hpp
#define bank_hpp

#include <stdio.h>
#include <string>
#include <iostream>
using namespace std;

class Bank
{
private:
    string name;
    string account;
    double money;
    
public:
    Bank();
    Bank(const string & n, const string & a, double m = 0);
    ~Bank();
    void money_in(double amount);
    void money_out(double amount);
    void show() const;
};

#endif /* bank_hpp */
