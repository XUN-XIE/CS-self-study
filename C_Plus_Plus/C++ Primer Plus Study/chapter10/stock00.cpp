//
//  stock00.cpp
//  chapter10
//
//  Created by 谢逊 on 2020/1/14.
//  Copyright © 2020 谢逊. All rights reserved.
//

#include "stock00.hpp"
#include <iostream>
using namespace std;

void Stock::acquire(const string & co, long n, double pr)
{
    using namespace std;
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

void Stock::show()
{
    using namespace std;
    cout << "Compamy: " << company
    << " Shares: " << shares << ".\n"
    << " Share Price: $" << share_val
    << " Total Worth: $" << total_val << '\n';
}
