//
//  main.cpp
//  e9.5
//
//  Created by 谢逊 on 2020/1/16.
//  Copyright © 2020 谢逊. All rights reserved.
//

#include <iostream>

#include "namesp.hpp"

void other(void);
void another(void);

int main()
{
    using debts::Debt;
    using debts::showDebt;
    
    Debt golf = {
        {"Benny", "Goatsniff"},
            120.0
        };
    showDebt(golf);
    other();
    another();
    
    return 0;
}

void other(void)
{
    using std::cout;
    using std::endl;
    using namespace debts;
    
    Person dg = {"Doodles", "Glister"};
    showPerson(dg);
    cout << endl;
    
    Debt zippy[3];
    
    for (int i = 0; i < 3; i++)
        getDebt(zippy[i]);
    
    for (int i = 0; i < 3; i++)
        showDebt(zippy[i]);
    cout << "Total debt: $" << sumDebts(zippy, 3) << endl;
    
    return;
}

void another(void)
{
    using pers::Person;
    
    Person collector = { "Milo", "Rightshift" };
    pers::showPerson(collector);
    std::cout << std::endl;
}
