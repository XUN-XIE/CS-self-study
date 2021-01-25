//
//  main.cpp
//  4.15
//
//  Created by 谢逊 on 2020/1/12.
//  Copyright © 2020 谢逊. All rights reserved.
//

#include <iostream>

int main()
{
    using namespace std;
    int updates = 6;
    int * p_updates;
    p_updates = &updates;
    
    cout << "Values: updates = " << updates;
    cout << ", *p_updates = " << *p_updates << endl;
    
    cout << "Addresses: &updates = " << &updates;
    cout << ", p_updates = " << p_updates << endl;
    
    *p_updates = *p_updates + 1;
    cout << "Now updates = " << updates << endl;
    
    return 0;

}
