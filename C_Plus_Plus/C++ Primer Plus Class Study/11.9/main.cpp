//
//  main.cpp
//  11.9
//
//  Created by 谢逊 on 2020/1/18.
//  Copyright © 2020 谢逊. All rights reserved.
//

#include <iostream>
#include "stonewt.hpp"

int main()
{
    Stonewt popins(9, 2.8);
    double p_wt = (double) popins;
    cout << "Convert to double => ";
    cout << "Popins: " << p_wt << " pounds.\n";
    cout << "Convert to int => ";
    cout << "Popins: " << int (popins) << " pounds.\n";
    
    return 0;
}
