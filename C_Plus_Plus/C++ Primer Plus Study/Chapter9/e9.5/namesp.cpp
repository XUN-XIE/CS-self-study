//
//  namesp.cpp
//  C++_Primer
//
//  Created by 谢逊 on 2020/1/16.
//  Copyright © 2020 谢逊. All rights reserved.
//

#include "namesp.hpp"
#include <iostream>

namespace pers
{
using std::cout;
using std::cin;
void getPerson(Person & rp)
{
    cout << "Enter first name: ";
    cin >> rp.fname;
    cout << "Enter last name: ";
    cin >> rp.lname;
}

void showPerson(const Person & rp)
{
    std::cout << rp.lname << ", " << rp.fname;
}
}


namespace debts
{
void getDebt(Debt & rd)
{
    getPerson(rd.name);
    std::cout << "Enter debt: ";
    std::cin >> rd.amount;
}

void showDebt(const Debt & rd)
{
    showPerson(rd.name);
    std::cout << ": $" << rd.amount << std::endl;
}

double sumDebts(const Debt ar[], int n)
{
    double total = 0;
    for (int i = 0; i < n; i++)
        total += ar[i].amount;
    return total;
}
}
