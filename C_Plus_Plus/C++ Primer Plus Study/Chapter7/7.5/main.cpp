//
//  main.cpp
//  7.5
//
//  Created by 谢逊 on 2020/1/14.
//  Copyright © 2020 谢逊. All rights reserved.
//

#include <iostream>
using namespace std;
const int Arsize = 8;

int sum_arr(int arr[], int n);

int main()
{
    int cookies[Arsize] = {1,2,4,8,16,32,64,128};
    
    int sum = sum_arr(cookies, Arsize);
    cout << "Total cookies eaten: " << sum << "\n";
    
    return 0;
}

int sum_arr(int arr[], int n)
{
    int total = 0;
    for (int i = 0; i < n; i++)
        total += arr[i];
    
    return total;
}
