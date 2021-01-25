//
//  main.cpp
//  11.4
//
//  Created by 谢逊 on 2020/1/18.
//  Copyright © 2020 谢逊. All rights reserved.
//

#include <iostream>
#include "mytime1.hpp"

int main()
{
    using std::endl;
    Time planning;
    Time coding(2, 40);
    Time fixing(5, 55);
    Time total;
    
    cout << "planning time = ";
    planning.Show();
    cout << endl;
    
    cout << "coding time = ";
    coding.Show();
    cout << endl;
    
    
    cout << "fixing time = ";
    fixing.Show();
    cout << endl;
    
//    total = coding.operator+(fixing);
    total = coding + fixing;
    cout << "coding.Sum(fixing) = ";
    total.Show();
    cout << endl;
    
    return 0;
}
