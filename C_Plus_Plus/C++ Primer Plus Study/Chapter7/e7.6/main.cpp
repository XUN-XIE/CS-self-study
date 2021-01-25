//
//  main.cpp
//  e7.6
//
//  Created by 谢逊 on 2020/1/15.
//  Copyright © 2020 谢逊. All rights reserved.
//

#include <iostream>

using namespace std;

int Fill_array(double * arr, int n);
void Show_array(const double * arr, int n);
void Reverse_array(double * arr, int n);

int main()
{
    int n = 0;
    double arr[10];
    n = Fill_array(arr, 10);
    Show_array(arr, n);
    
    Reverse_array(arr, n);
    Show_array(arr, n);
    
    return 0;
}

int Fill_array(double * arr, int n)
{
    cout << "Enter" << endl;
    int i = 0;
    while (i != n && cin >> arr[i++]);
    
    return i - 1;
}

void Show_array(const double * arr, int n)
{
    for (int i = 0; i != n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

void Reverse_array(double * arr, int n)
{
    double temp;
    for (int i = 0; i != n/2; i++)
    {
        temp = arr[i];
        arr[i] = arr[n-i-1];
        arr[n-i-1] = temp;
    }
}
