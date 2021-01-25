//
//  main.cpp
//  4.17
//
//  Created by 谢逊 on 2020/1/12.
//  Copyright © 2020 谢逊. All rights reserved.
//

#include <iostream>

int main()
{
    using namespace std;
    int nights = 1001;
    int * pt = new int;
    *pt = 1001;
    
    cout << "nights value = " << nights << ": location " << &nights << endl;
    
    cout << "init ";
    cout << "value = " << *pt << ": location = " << pt << endl;
    
    double * pd = new double;
    *pd = 10000001.0;
    
    cout << "double " << "value = " << *pd << ": locatioin = " << pt << endl;
    cout << "location of pointer pd: " << &pd << endl;
    
    cout << "size of pt = " << sizeof(pt);
    cout << ": size of *pt = " << sizeof(*pt) << endl;
    cout << "size of pd = " << sizeof(pd);
    cout << ": size of *pd = " << sizeof(*pd) << endl;
}
