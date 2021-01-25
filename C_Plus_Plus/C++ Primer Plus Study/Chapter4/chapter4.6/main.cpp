//
//  main.cpp
//  chapter4.6
//
//  Created by 谢逊 on 2020/1/11.
//  Copyright © 2020 谢逊. All rights reserved.
//

#include <iostream>
using namespace std;

int main()
{
    enum bits { one = 1, two = 2, four = 4, eight = 8};

    cout << bits(one) << endl;
    
    return 0;
}
