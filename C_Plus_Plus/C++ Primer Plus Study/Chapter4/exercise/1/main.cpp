//
//  main.cpp
//  1
//
//  Created by 谢逊 on 2020/1/12.
//  Copyright © 2020 谢逊. All rights reserved.
//

#include <iostream>
#include <string>

using namespace std;

int main()
{
    string first, last;
    char letter;
    int age;
    
    cout << "What is your first name? ";
    getline(cin, first);
    
    cout << "What is your last name? ";
    getline(cin, last);
    
    cout << "What letter grade do you deserve? ";
    cin >> letter;
    
    cout << "What is your age? ";
    cin >> age;
    
    cout << "Name: " << last << ", " << first << endl;
    cout << "Grade: " << char(letter + 1) << endl;
    cout << "Age: " << age << endl;
    
    return 0;
}
