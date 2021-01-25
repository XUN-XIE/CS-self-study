//
//  main.cpp
//  4.19
//
//  Created by 谢逊 on 2020/1/12.
//  Copyright © 2020 谢逊. All rights reserved.
//

#include <iostream>

int main()
{
    using namespace std;
    double wages[3] = {10000.0, 20000.0, 30000.0};
    short stacks[3] = {3, 2, 1};
    
    double * pw = wages;
    short * ps = &stacks[0];
    
    cout << "pw = " << pw << ", *pw = " << *pw << endl;
    
    pw = pw + 1;
    
    cout << "add 1 to the pw pointer:\n";
    cout << "pw = " << pw << ", *pw = " << *pw << "\n\n";
    cout << "ps = " << ps << ", *ps = " << *ps << endl;
    
    ps = ps + 1;
    
    cout << "add 1 to the ps pointer:\n";
    cout << "ps = " << ps << ", *ps = " << *ps << "\n\n";
    
    cout << "access two elements with array notation\n";
    cout << "stacks[0] = " << stacks[0] << ", stack[1] = " << stacks[1] << endl;
    
    cout << "access two elements with poiinter notatioin\n";
    cout << "*stacks = " << *stacks << ", *(stacks + 1) = " << *(stacks + 1) << endl;
    
    cout << sizeof(wages) << " = size of wages array\n";
    cout << sizeof(pw) << " = siize of pw pointer\n";
    
    return 0;
}
