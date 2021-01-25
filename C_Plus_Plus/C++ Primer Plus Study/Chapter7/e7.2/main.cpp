//
//  main.cpp
//  e7.2
//
//  Created by 谢逊 on 2020/1/15.
//  Copyright © 2020 谢逊. All rights reserved.
//

#include <iostream>

using namespace std;

void average(double * arr, int n);

int main()
{
    double scores[10];
    int i = 0;
    
    while (i != 10 && cin >> scores[i++]);
    
    average(scores, i);
        
}

void average(double * arr, int n)
{
    double total = 0.0;
    for (int i = 0; i < n; i++)
    {
        total += arr[i];
        cout << arr[i] << " ";
    }
    cout << endl;
    
    cout << total / n << endl;
}
