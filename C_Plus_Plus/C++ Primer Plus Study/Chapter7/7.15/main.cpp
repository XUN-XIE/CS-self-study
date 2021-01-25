//
//  main.cpp
//  7.15
//
//  Created by 谢逊 on 2020/1/15.
//  Copyright © 2020 谢逊. All rights reserved.
//

#include <iostream>
#include <array>
#include <string>

const int Seasons = 4;
using namespace std;
const array<string, Seasons> Snames = {"Spring", "Summer", "Fall", "Winter"};

void fill(array<double, Seasons> * pa);
void show(array<double, Seasons> da);

int main()
{
    array<double, Seasons> expenses;
    fill(&expenses);
    show(expenses);
    
    return 0;
}

void fill(array<double, Seasons> * pa)
{
    for (int i = 0; i < Seasons; i++)
    {
        cout << "Enter" << Snames[i] << " expenses: ";
        cin >> (*pa)[i];
    }
}


void show(array<double, Seasons> da)
{
    double total = 0.0;
    cout << "\nEXPENSES\n";
    
    for (int i = 0; i < Seasons; i++)
    {
        cout << Snames[i] << ": $" << da[i] << endl;
        total += da[i];
    }
    cout << "Total Expenses: $" << total << endl;
}
