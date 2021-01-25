//
//  main.cpp
//  exercise4
//
//  Created by 谢逊 on 2020/1/13.
//  Copyright © 2020 谢逊. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>
#include <cstring>
#include <cmath>
#include <algorithm>

using namespace std;

/* exercise2
double med(vector<double> v);

double med(vector<double> v)
{
    if (v.size() % 2 == 1)
        return v[v.size()/2];
    else
        return (v[v.size()/2 - 1] + v[v.size()/2]) / 2.0;
}

 
int main()
{
    vector<double> v = {1,2,3,4};
    
    cout << med(v);
}
*/


/* exercise3
int main()
{
    vector<double> v = {100.0,1.2,3.4,5.6,7.8};
    
    double sum = 0;
    
    for (double x: v)
        sum += x;
    
    sort(&v[0], &v[v.size()]);
    
    cout << "the sum of distance: " << sum << endl;
    cout << "smallest: " << v[0] << endl;
    cout << "largest: " << v[v.size() - 1] << endl;
}
*/

/* exercise4
int main()
{
    int answer = 17;
    int guess = 50;
    int number = 0;
    int upp = 100;
    int low = 0;
    
    
    while (answer != guess)
    {
        number++;
        cout << "you guess " << guess << endl;
        if (guess > answer)
        {
            upp = guess;
            guess = (low + guess) / 2;
        }
        else
        {
            low = guess;
            guess = (upp + guess) / 2;
        }
    }
    
    cout << "answer: " << answer << endl;
    cout << "guess: " << guess << endl;
    cout << "you guess " << number << " times" << endl;
}
*/


/* exercise5
int main()
{
    double first;
    double second;
    char operation;
    double result;
    
    cout << "Please enter first number: ";
    cin >> first;
    
    cout << "Please enter operation: ";
    cin >> operation;
    
    cout << "Please enter second number: ";
    cin >> second;
    
    switch (operation)
    {
        case '+':
            result = first + second;
            break;
        case '-':
            result = first - second;
            break;
        case '*':
            result = first * second;
            break;
        case '/':
            if (second == 0)
            {
                cout << "Your denominator is 0, it is wrong!" << endl;
                break;
            }
            result = first / second;
            break;
            
    }
    
    if (second != 0 || operation != '/')
        cout << "ouput is: " << result << endl;
}
*/


