//
//  main.cpp
//  11.7
//
//  Created by 谢逊 on 2020/1/18.
//  Copyright © 2020 谢逊. All rights reserved.
//

#include <iostream>
#include "mytime2.hpp"

int main()
{
    using std::endl;
    
    Time weeding(4, 35);
    Time waxing(2, 47);
    Time total;
    Time diff;
    Time adjusted;
    
    cout << "weeding time = ";
    weeding.Show();
    cout << endl;
    
    cout << "waxing time = ";
    waxing.Show();
    cout << endl;
    
    cout << "total time = ";
    total = weeding + waxing;
    total.Show();
    cout << endl;
    
//    total = coding.operator+(fixing);
    diff = weeding - waxing;
    cout << "diff = ";
    diff.Show();
    cout << endl;
    
    adjusted = total * 1.5;
    cout << "adjusted work time = ";
    adjusted.Show();
    cout << endl;
    
    return 0;
}
