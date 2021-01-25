//
//  main.cpp
//  exercise10.1
//
//  Created by 谢逊 on 2020/1/16.
//  Copyright © 2020 谢逊. All rights reserved.
//

#include <iostream>
#include "bank.hpp"

int main()
{
    Bank exp1;
    Bank exp2 = Bank("xiexun", "12345678", 8888.0);
    Bank exp3("guang", "87654321", 6666.0);
    
    exp1.show();
    exp2.show();
    exp3.show();
    
    double transfer = 999;
//    cout << exp2.name << " transfer $" << transfer << " to " << exp3.name << endl;
    exp2.money_out(transfer);
    exp3.money_in(transfer);
    exp2.show();
    exp3.show();
    
    return 0;
}
