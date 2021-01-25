//
//  main.cpp
//  8.2
//
//  Created by 谢逊 on 2020/1/15.
//  Copyright © 2020 谢逊. All rights reserved.
//

#include <iostream>

int main()
{
    using namespace std;
    
    int rats = 101;
    int & rodents = rats;
    cout << "rats = " << rats;
    cout << ", rodents = " << rodents << endl;
    
    rodents++;
    cout << "rats = " << rats;
    cout << ", rodents = " << rodents << endl;
    
    rats++;
    cout << "rats = " << rats;
    cout << ", rodents = " << rodents << endl;
    
    cout << "rats address: " << &rats;
    cout << ", rodents address: " << &rodents << endl;
    
    return 0;
}
