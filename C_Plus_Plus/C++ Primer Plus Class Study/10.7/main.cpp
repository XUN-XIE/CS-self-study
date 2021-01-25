//
//  main.cpp
//  10.7
//
//  Created by 谢逊 on 2020/1/16.
//  Copyright © 2020 谢逊. All rights reserved.
//

#include <iostream>
#include "stock20.hpp"

const int STK = 4;

int main()
{
    Stock stocks[STK] =
    {
        Stock("NanoSmart", 12, 20.0),
        Stock("Boffo Objects", 200, 2.0),
        Stock("Monolithic Obelisks", 130, 3.25),
        Stock("Fleep Enterprises", 60, 6.5)
    };
    
    cout << "Stock holdings:\n";
    int st;
    for (st = 0; st < STK; st++)
        stocks[st].show();
    const Stock * top = &stocks[0];
    for (st = 1; st < STK; st++)
        top = &top->topval(stocks[st]);
    
    cout << "\nMost valuable holding:\n";
    top->show();
    
    return 0;
}

