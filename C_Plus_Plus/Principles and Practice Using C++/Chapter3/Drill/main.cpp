//
//  main.cpp
//  Drill
//
//  Created by 谢逊 on 2020/1/13.
//  Copyright © 2020 谢逊. All rights reserved.
//

#include <iostream>
#include <string>
#include "std_lib_facilities.h"

using namespace std;

int main()
{
    cout << "Enter the name of person you want to write in: ";
    string first = "???";
    cin >> first;
    cout <<"Dear, " << first << " . How are you? I'm fine" << endl;
    
    string fri_name = "???";
    cout << "Enter the name of friend you want to write in: ";
    cin >> fri_name;
    cout << "Have you seen " << fri_name << " lately." << endl;
    
    char friend_sex = 0;

    cout << "Enter the sex of your friend, 'm' represents the male and 'f' represents the female: ";
    cin >> friend_sex;
    if (friend_sex == 'm')
        cout << "If you see " << fri_name << " lease ask him to call me.";
    if (friend_sex == 'f')
        cout << "If you see " << fri_name << " lease ask her to call me.";
    cout << endl;
    
    int age = -1;
    cout << "Enter the age of your friends: ";
    cin >> age;
    
    if (age < 0 || age > 110)
    {
        cout << "You are kidding!" << endl;
        simple_error("you're kidding!");
    }
    cout << "I hear you just had a birthday and you are " << age << " years old." << endl;
    
    if (age < 12)
        cout << "Next year you will be " << age + 1;
    if (age == 17)
        cout << "Next year you will be able vote.";
    if (age > 70)
        cout << "I hope you are enjoying retirement";
    
    cout << "\n\n";
    
    cout << first;
    cout << "\n\n";
    
    cout << "Yours sincerely!" << endl;
    
    return 0;
}
