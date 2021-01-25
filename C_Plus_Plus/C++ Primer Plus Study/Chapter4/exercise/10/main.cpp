//
//  main.cpp
//  10
//
//  Created by 谢逊 on 2020/1/12.
//  Copyright © 2020 谢逊. All rights reserved.
//

#include <iostream>
#include <array>

using namespace std;

int main()
{
    array<double, 3> arr;
    
    cin >> arr[0];
    cin >> arr[1];
    cin >> arr[2];
    
    cout << (arr[0] + arr[1] + arr[2]) / 3.0 << endl;
}
