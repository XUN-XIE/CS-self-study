//
//  namesp.hpp
//  Chapter9
//
//  Created by 谢逊 on 2020/1/16.
//  Copyright © 2020 谢逊. All rights reserved.
//

#ifndef namesp_hpp
#define namesp_hpp

#include <string>

namespace pers
{
    struct Person
    {
        std::string fname;
        std::string lname;
    };
void getPerson(Person &);
void showPerson(const Person &);
};


namespace debts
    {
    using namespace pers;
    struct Debt
    {
        Person name;
        double amount;
    };
    void getDebt(Debt &);
    void showDebt(const Debt &);
    double sumDebts(const Debt ar[], int n);
    };

#endif /* namesp_hpp */
