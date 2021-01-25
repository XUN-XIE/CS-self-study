//
//  main.cpp
//  e9.4
//
//  Created by 谢逊 on 2020/1/16.
//  Copyright © 2020 谢逊. All rights reserved.
//

#include <iostream>
#include "namesp.hpp"

using namespace SALES;

int main()
{
    Sales s;
    double ar[2] = {123,456};
    setSales(s, ar, 2);
    showSales(s);
    
    setSales(s);
    showSales(s);
}
