//
//  main.cpp
//  e8.4
//
//  Created by 谢逊 on 2020/1/15.
//  Copyright © 2020 谢逊. All rights reserved.
//

#include <iostream>
using namespace std;
#include <cstring>



struct stringy
{
    char * str;
    int ct;
};

void set(stringy & str, char * input);
void show(const stringy & str, int n = 1);

template <class T>
void show(const T &  str, int n = 1);

int main()
{
    stringy beany;
    char testing[] = "Really isn't what it used to be.";
    
    set(beany, testing);
    
    show(beany);
    show(beany, 2);
    testing[0] = 'D';
    testing[1] = 'u';
    show(testing);
    show(testing, 3);
    show("Done!");
    
    return 0;
}

void set(stringy & str, char * input)
{
    str.str = input;
    str.ct = 1;
}

void show(const stringy & str, int n)
{
    for (int i = 0; i < n; i++)
        cout << str.str << endl << str.ct << endl;
}

template <class T>
void show(const T & str, int n)
{
    for (int i = 0; i < n; i++)
        cout << str << endl;
}
