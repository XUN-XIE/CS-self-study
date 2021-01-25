//
//  main.cpp
//  4.14
//
//  Created by 谢逊 on 2020/1/12.
//  Copyright © 2020 谢逊. All rights reserved.
//

#include <iostream>

using namespace std;

int main()
{
    enum bits { one = 1, two = 2, four = 4, eight = 8};
    int donuts = 6;
    double cups = 4.5;
    
    cout << "donuts value = " << donuts;
    cout << " and donuts address = " << &donuts << endl;
    
    cout << "cups value = " << cups;
    cout << " and cups address = " << &cups << endl;
    
    return 0;
}

