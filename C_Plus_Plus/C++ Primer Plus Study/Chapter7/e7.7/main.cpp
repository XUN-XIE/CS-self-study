//
//  main.cpp
//  e7.7
//
//  Created by 谢逊 on 2020/1/15.
//  Copyright © 2020 谢逊. All rights reserved.
//

#include <iostream>

using namespace std;

const int Max = 5;

double * fill_array(double ar[], int limit);
void show_array(const double ar[], double * last);
void revalue(double r, double ar[], double * last);

int main()
{
    double properties[Max];
    
    double * last = fill_array(properties, Max);
    show_array(properties, last);
    
    if (int(last-properties) > 0)
    {
        cout << "Enter revaluation factor: ";
        
        double factor;
        while (!(cin >> factor))
        {
            cin.clear();
            while (cin.get() != '\n')
                continue;
            cout << "Bad input; Please enter a number: ";
            
        }
        
        revalue(factor, properties, last);
        show_array(properties, last);
    }
    cout << "Done.\n";
    cin.get();
    cin.get();
    
    return 0;
}


double * fill_array(double ar[], int limit)
{
    double temp;
    int i;
    
    for (i = 0; i != limit; i++)
    {
        cout << "Enter value #" << (i + 1) << ": ";
        cin >> temp;
        if (!cin)
        {
        cin.clear();
        while (cin.get() != '\n')
            continue;
        cout << "Bad input; input precess terminated.\n";
        break;
        }
        else if (temp < 0)
            break;
        ar[i] = temp;
    }
    
    return &(ar[i]);
}


void show_array(const double ar[], double * last)
{
    for (int i = 0; i != int(last-ar); i++)
    {
        cout << "Property #" << (i + 1) << ": $";
        cout << ar[i] << endl;
    }
}

void revalue(double r, double ar[], double * last)
{
    for (int i = 0; i != int(last-ar); i++)
        ar[i] *= r;
}
