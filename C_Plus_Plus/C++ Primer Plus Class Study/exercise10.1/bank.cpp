//
//  bank.cpp
//  exercise10.1
//
//  Created by 谢逊 on 2020/1/16.
//  Copyright © 2020 谢逊. All rights reserved.
//

#include "bank.hpp"

Bank::Bank()
{
    name = "";
    account = "00000000";
    money = 0;
}

Bank::Bank(const string & n, const string & a, double m)
{
    name = n;
    account = a;
    money = m;
}

Bank::~Bank()
{
    cout << "Bye" << name << endl;
}

void Bank::money_in(double amount)
{
    money += amount;
}

void Bank::money_out(double amount)
{
    if (money < amount)
    {
        cout << "Sorry! you cannot take out more money than you have" << endl;
        cout << "So, you have taken out $" << money << endl;
        money = 0;
    }
    else
        money -= amount;
}

void Bank::show() const
{
    cout << "name: " << name << endl;
    cout << "account: " << account << endl;
    cout << "amount: " << money << endl;
}
