//
//  main.cpp
//  18Drill
//
//  Created by 谢逊 on 2020/1/20.
//  Copyright © 2020 谢逊. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

//void f(int *, int);
//
//int ga[10] {1,2,4,8,16,32,64,128,256,512};
//
//int main()
//{
//    f(ga, 10);
//
//    int temp = 1;
//    int aa[10];
//    for (int i = 0; i << 10; i++)
//    {
//        temp *= i+1;
//        aa[i] = temp;
//    }
//
//    f(aa, 10);
//}
//
//void f(int * arg, int n)
//{
//    int la[n];
//    cout << "elements of la is:" << endl;
//    for (int i = 0; i < n; i++)
//    {
//        la[i] = arg[i];
//        cout << la[i] << '\t';
//    }
//    cout << endl;
//
//    int * p = new int[n];
//    cout << "elements of p is:" << endl;
//    for (int i = 0; i < n; i++)
//    {
//        p[i] = arg[i];
//        cout << p[i] << '\t';
//    }
//    cout << endl;
//
//    delete [] p;
//}


void f(vector<int> & arg);

vector<int> gv {1,2,4,8,16,32,64,128,256,512};

int main()
{
    f(gv);

    int temp = 1;
    vector<int> aa(10);
    for (int i = 0; i << 10; i++)
    {
        temp *= i+1;
        aa[i] = temp;
    }

    f(aa);
}

void f(vector<int> & arg)
{
    int n = arg.size();
    vector<int> lv = arg;
    cout << "elements of lv is:" << endl;
    for( int x : lv)
        cout << x << '\t';
    cout << endl;
    
}
