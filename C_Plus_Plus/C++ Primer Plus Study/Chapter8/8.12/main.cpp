//
//  main.cpp
//  8.12
//
//  Created by 谢逊 on 2020/1/15.
//  Copyright © 2020 谢逊. All rights reserved.
//

#include <iostream>

template <class T>
void Swap(T & a, T & b);

template <class T>
void Swap(T * a, T * b, int n);
void Show(int a[]);
const int Lim = 8;

int main()
{
    using namespace std;
    int i = 10;
    int j = 20;
    cout << "i, j = " << i << ", " << j << ".\n";
    Swap(i,j);
    cout << "Now i, j = " << i << ", " << j << ".\n";
    
    int d1[Lim] = {0,7,0,4,1,7,7,6};
    int d2[Lim] = {0,7,2,0,1,9,6,9};
    cout << "Original arrays: \n";
    Show(d1);
    Show(d2);
    Swap(d1,d2,Lim);
    cout << "Swapped arrays: \n";
    Show(d1);
    Show(d2);
    
    return 0;
}

template <class T>
void Swap(T & a, T & b)
{
    T temp;
    temp = a;
    a = b;
    b = temp;
}

template <class T>
void Swap(T a[], T b[], int n)
{
    T temp;
    for (int i = 0; i < n; i++)
    {
        temp = a[i];
        a[i] = b[i];
        b[i] = temp;
    }
}

void Show(int a[])
{
    using namespace std;
    cout << a[0] << a[1] << "/";
    cout << a[2] << a[3] << "/";
    for (int i = 4; i < Lim ; i++)
        cout << a[i];
    cout << endl;
}
