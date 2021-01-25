//
//  main.cpp
//  e8.5
//
//  Created by 谢逊 on 2020/1/15.
//  Copyright © 2020 谢逊. All rights reserved.
//

#include <iostream>

using namespace std;

template <class T>
T max5(T a[]);

int main()
{
    int arr[5] = {1,2,3,4,5};
    double arr2[5] = {1.23, 4.56,7.89,12.34,56.78};
    
    int maxint;
    double maxdouble;
    
    maxint = max5(arr);
    maxdouble = max5(arr2);
    
    cout << maxint << endl << maxdouble << endl;
}

template <class T>
T max5(T a[])
{
    T max = 0;
    for (int i = 0; i != 5; i++)
    {
        if (a[i] > max)
            max = a[i];
    }
    return max;
}
