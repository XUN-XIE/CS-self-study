//
//  Person.hpp
//  exercise10.2
//
//  Created by 谢逊 on 2020/1/16.
//  Copyright © 2020 谢逊. All rights reserved.
//

#ifndef Person_hpp
#define Person_hpp

#include <stdio.h>
#include <iostream>
#include <string>
using namespace std;

class Person {
private:
    static const int LIMIT = 25;
    string lname;
    char fname[LIMIT];
    
public:
    Person() { lname = ""; fname[0] = '\0'; };
    Person(const string & ln, const char * fn = "Heyyou");
    
    void show() const;
    void Formalshow();
};

#endif /* Person_hpp */
