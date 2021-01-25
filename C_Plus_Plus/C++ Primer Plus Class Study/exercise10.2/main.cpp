//
//  main.cpp
//  exercise10.2
//
//  Created by 谢逊 on 2020/1/16.
//  Copyright © 2020 谢逊. All rights reserved.
//

#include <iostream>
#include "Person.hpp"

int main()
{
    Person one;
    Person two("Smythecraft");
    Person three("Dimwiddy", "Sam");
    one.show();
    two.show();
    three.show();
//    one.Formalshow();
    
    return 0;
}
