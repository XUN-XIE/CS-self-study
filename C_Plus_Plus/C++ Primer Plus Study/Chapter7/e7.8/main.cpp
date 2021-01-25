//
//  main.cpp
//  e7.8
//
//  Created by 谢逊 on 2020/1/15.
//  Copyright © 2020 谢逊. All rights reserved.
//

#include <iostream>
#include <array>
#include <string>

const int Seasons = 4;
using namespace std;

const char * Snames[4] = {"Spring", "Summer", "Fall", "Winter"};

//void fill(double * pa);
//void show(double * da);
//
//int main()
//{
//    double expenses[Seasons];
//    fill(expenses);
//    show(expenses);
//
//    return 0;
//}
//
//void fill(double * pa)
//{
//    for (int i = 0; i < Seasons; i++)
//    {
//        cout << "Enter" << Snames[i] << " expenses: ";
//        cin >> pa[i];
//    }
//}
//
//
//void show(double * da)
//{
//    double total = 0.0;
//    cout << "\nEXPENSES\n";
//
//    for (int i = 0; i < Seasons; i++)
//    {
//        cout << Snames[i] << ": $" << da[i] << endl;
//        total += da[i];
//    }
//    cout << "Total Expenses: $" << total << endl;
//}

//struct arr
//{
//    double expenses[Seasons];
//};
//
//void fill(arr * pa);
//void show(arr * da);
//
//int main()
//{
//    arr exp;
//    fill(&exp);
//    show(&exp);
//
//    return 0;
//}
//
//void fill(arr * pa)
//{
//    for (int i = 0; i < Seasons; i++)
//    {
//        cout << "Enter " << Snames[i] << " expenses: ";
//        cin >> pa->expenses[i];
//    }
//}
//
//
//void show(arr * da)
//{
//    double total = 0.0;
//    cout << "\nEXPENSES\n";
//
//    for (int i = 0; i < Seasons; i++)
//    {
//        cout << Snames[i] << ": $" << da->expenses[i] << endl;
//        total += da->expenses[i];
//    }
//    cout << "Total Expenses: $" << total << endl;
//}

struct arr
{
    double expenses[Seasons];
};

arr fill(arr pa);
arr show(arr da);

int main()
{
    arr * temp = new arr;
    arr exp;
    *temp = fill(exp);
    show(*temp);

    return 0;
}

arr fill(arr pa)
{
    for (int i = 0; i < Seasons; i++)
    {
        cout << "Enter " << Snames[i] << " expenses: ";
        cin >> pa.expenses[i];
    }
    
    return pa;
}


arr show(arr da)
{
    double total = 0.0;
    cout << "\nEXPENSES\n";

    for (int i = 0; i < Seasons; i++)
    {
        cout << Snames[i] << ": $" << da.expenses[i] << endl;
        total += da.expenses[i];
    }
    cout << "Total Expenses: $" << total << endl;
    
    return da;
}
