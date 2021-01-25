//
//  main.cpp
//  7.8
//
//  Created by 谢逊 on 2020/1/14.
//  Copyright © 2020 谢逊. All rights reserved.
//

#include <iostream>
using namespace std;
const int Arsize = 8;

int sum_arr(int * begin, int * end);

int main()
{
    int cookies[Arsize] = {1,2,4,8,16,32,64,128};
    cout << cookies << " = array address, ";
    cout << sizeof(cookies) << " = sizeof cookies\n";
    
    int sum = sum_arr(cookies, cookies + Arsize);
    cout << "Total cookies eaten: " << sum << "\n";
    
    sum = sum_arr(cookies, cookies + 3);
    cout << "First three eaters ate " << sum << " cookies.\n";
    
    sum = sum_arr(cookies + 4, cookies + 8);
    cout << "Last four eaters ate " << sum << " cookies.\n";
    
    return 0;
}

int sum_arr(int * begin, int * end)
{
    const int * pt;
    int total = 0;

    for (pt = begin; pt != end; pt++)
        total += *pt;
    
    return total;
}
