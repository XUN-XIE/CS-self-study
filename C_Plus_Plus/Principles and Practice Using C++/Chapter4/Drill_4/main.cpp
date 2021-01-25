//
//  main.cpp
//  Drill_4
//
//  Created by 谢逊 on 2020/1/13.
//  Copyright © 2020 谢逊. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>

using namespace std;
//
//int main()
//{
//    double first;
//    double second;
//    cout << "Enter two values you want to print out." << endl;
//    while (cin>> first >> second && first != '|' && second != '|')
//    {
//        cout << "Two number are: " << first << " " << second << endl;
//
//        double diff = first - second;
//
//        if (diff < 0.01 && diff > -0.01)
//             cout << "the numbers are almost equal." << endl;
//
//        else
//        {
//            if (first > second)
//            {
//                cout << "The smaller value is: " << second << endl;
//                cout << "The larger value is: " << first << endl;
//            }
//
//            else if (first < second)
//                {
//                    cout << "The smaller value is: " << first << endl;
//                    cout << "The larger value is: " << second << endl;
//                }
//        }
//
//        cout << "If you want to quit, please input '|'." << endl;
//    }
//}


int main()
{
    double value;
    double smallest;
    double largest;
    string units;
    char unit;
    double sum = 0;
    int number = 0;
    
    vector<double> v;
    
//    cout << "value is " << value << endl;
//    cout << "unit is " << unit << endl;

    cout << "Enter values you want to print out." << endl;
    
    while (cin >> value >> units && value != '|')
    {
        if (number == 0)
        {
            smallest = value;
            largest = value;
        }
        cout << "value is " << value << endl;
        cout << "unit is " << units << endl;
        
        unit = units[0];
        
        switch (unit)
        {
            case 'c':
                break;
            case 'm':
                value *= 100;
                cout << value << endl;
                break;
            case 'i':
                value *= 2.54;
                break;
            case 'f':
                value = value *  12 * 2.54;
                break;
            default:
                cout << "Sorry, you input a wrong unit.";
                cout << "Please input again or quit. ";
                cout << "If you want to quit, please input '|'." << endl;
                continue;
        }
        
        v.push_back(value/100);
        
        sum += value;
        number += 1;
        cout << "value is: " << value <<"cm " << endl;
        
        if (value < smallest)
        {
            cout  << "the smallest so far." << endl;
            smallest = value;
        }
        
        if (value > largest)
        {
            cout  << "the largest so far." << endl;
            largest = value;
        }
        
        cout << "If you want to quit, please input '|'." << endl;
    }
    
    cout << "the smallest value: " << smallest << endl;
    cout << "the largest value: " << largest << endl;
    cout << "number of values are: " << number << endl;
    cout << "sum of values are: " << sum/100 << "m" << endl;
    
    sort(&v[0], &v[v.size()]);
    
    cout << "all the values in unit meters are:" << endl;
    for (double x: v)
        cout << x << "\n";
}
