//
//  Person.cpp
//  exercise10.2
//
//  Created by 谢逊 on 2020/1/16.
//  Copyright © 2020 谢逊. All rights reserved.
//

#include "Person.hpp"

Person::Person(const string & ln, const char * fn)
{
    lname = ln;
    for (int i = 0; i < LIMIT; i++)
        fname[i] = fn[i];
}

void Person::show() const
{
    cout << "last name: " << lname << endl;
    cout << "first name: " << fname << endl;
}

void Formalshow()
{
    cout << "Your name is: " << " " << endl;
}
