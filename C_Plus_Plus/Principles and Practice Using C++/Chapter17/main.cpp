//
//  main.cpp
//  Chapter17
//
//  Created by 谢逊 on 2020/1/20.
//  Copyright © 2020 谢逊. All rights reserved.
//

#include "Vector.hpp"


void print_array10(ostream & os, int * a);


int main()
{
    int * p = new int[10];
    for (int i = 0; i < 10; i++)
        cout << p[i] << '\t';
    cout << endl;
    delete [] p;
    
    p = new int[10];
    for (int i = 0; i < 10; i++)
    {
        if (i < 3)
            p[i] = 100 + i;
        cout << p[i] << '\t';
    }
    cout << endl;
    
    delete [] p;
    
    p = new int[11];
    for (int i = 0; i < 11; i++)
    {
        if (i < 3)
            p[i] = 100 + i;
        cout << p[i] << '\t';
    }
    cout << endl;
    
}

void print_array10(ostream & os, int * a)
{
    for (int i = 0; i < 10; i++)
        os << a[i] << '\t';
    os << endl;
}


//int main()
//{
//    cout << "double is: " << sizeof(double) << endl;
//    cout << "int is: " << sizeof(int) << endl;
//    cout << "bool is: " << sizeof(bool) << endl;
//    cout << "char is: " << sizeof(char) << endl;
//    cout << "char * is: " << sizeof(char *) << endl;
//    cout << "double* is: " << sizeof(double *) << endl;
//    cout << "int* is: " << sizeof(int *) << endl;
//    cout << "bool* is: " << sizeof(bool *) << endl;
//
//    vector<double> a(10);
//    for (int i = 0; i < 10; i++)
//    {
//        a[i] = i;
//    }
//    cout << "vector<double> 1000 is: " << sizeof(a) << endl;
//    vector<vector<double>> b(5);
//    for (int i = 0; i < 5; i++)
//    {
//        b[i] = a;
//    }
//    for (int i = 0; i < 5; i++)
//    {
//        for (int j = 0; j < 10; j++)
//            cout << b[i][j] << '\t';
//        cout << endl;
//    }
//
//
//}
