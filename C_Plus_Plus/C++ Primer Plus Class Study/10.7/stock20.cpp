//
//  stock20.cpp
//  10.7
//
//  Created by 谢逊 on 2020/1/16.
//  Copyright © 2020 谢逊. All rights reserved.
//

#include "stock20.hpp"
#include <iostream>

Stock::Stock()
{
    cout << "Default constructor called\n";
    company = "no name";
    shares = 0;
    share_val = 0.0;
    total_val = 0.0;
}

Stock::Stock(const string & co, long n, double pr)
{
    cout << "Constructor using " << co << " called\n";
    company = co;
    
    if (n < 0)
    {
        cout << "Number of shares can't be negative; " << company << " shares set to 0.\n";
        shares = 0;
    }
    else
        shares = n;
    share_val = pr;
    set_tot();
}

Stock::~Stock()
{
//    cout << "Bye, " << company << "!\n";
}

void Stock::buy(long num, double price)
{
    using namespace std;
    if (num < 0)
    {
        cout << "Number of shares purchased can't be negative. " << "Transaction is aborted.\n";
    }
    else
    {
        shares += num;
        share_val = price;
        set_tot();
    }
}

void Stock::sell(long num, double price)
{
    using namespace std;
    if (num < 0)
        cout << "Number of shares sell can't be negative. " << "Transaction is aborted.\n";
    else if (num > shares)
        cout << "You can't sell more than you have! Traansaction is aborted.\n";
    else
    {
        shares -= num;
        share_val = price;
        set_tot();
    }
}

void Stock::update(double price)
{
    share_val = price;
    set_tot();
}

void Stock::show() const
{
    using namespace std;
    cout << "Compamy: " << company
    << " Shares: " << shares << ".\n"
    << " Share Price: $" << share_val
    << " Total Worth: $" << total_val << '\n';
}

const Stock & Stock::topval(const Stock & s) const
{
    if (s.total_val > total_val)
        return s;
    else
        return *this;
}
