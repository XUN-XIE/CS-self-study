//
//  main.cpp
//  e7.5
//
//  Created by 谢逊 on 2020/1/15.
//  Copyright © 2020 谢逊. All rights reserved.
//

#include <iostream>

int factorial(int n);

using namespace std;

int main()
{
    int n;
    cin >> n;
    
    cout << factorial(n) << endl;
    
    return 0;
}

int factorial(int n)
{
    int result = 0;
    if (n == 0)
        return 1;
    return n * factorial(n-1);
}
