//
//  stringbad.cpp
//  12.1
//
//  Created by 谢逊 on 2020/1/18.
//  Copyright © 2020 谢逊. All rights reserved.
//

#include "stringbad.hpp"
 
int Stringbad::num_strings = 0;

Stringbad::Stringbad(const char * s)
{
    len = strlen(s);
    str = new char[len + 1];
    strcpy(str, s);
    num_strings++;
    cout << num_strings << ": \"" << str << "\" object created\n";
}

Stringbad::Stringbad()
{
    len = 4;
    str = new char[4];
    strcpy(str, "C++");
    num_strings++;
    cout << num_strings << ": \"" << str << "\" default object cerated\n";
}

Stringbad::~Stringbad()
{
    cout << "\"" << str << "\" object deleted";
    --num_strings;
    cout << num_strings << "left\n";
    delete [] str;
}

std::ostream & operator<<(std::ostream & os, const Stringbad & st)
{
    os << st.str;
    return os;
}
