//
//  main.cpp
//  e7.9
//
//  Created by 谢逊 on 2020/1/15.
//  Copyright © 2020 谢逊. All rights reserved.
//

#include <iostream>

using namespace std;

const int SLEN = 30;
struct student
{
    char fullname[SLEN];
    char hobby[SLEN];
    int ooplevel;
};

int getinfo(student pa[], int n);

void display1(student st);

void display2(student * ps);

void display3(const student pa[], int n);

int main()
{
    cout << "Enter class size: ";
    int class_size;
    cin >> class_size;
    
    while (cin.get() != '\n')
        continue;
    student * ptr_stu = new student[class_size];
    int entered = getinfo(ptr_stu, class_size);
    
    for (int i = 0; i < entered; i++)
    {
        display1(ptr_stu[i]);
        display2(&ptr_stu[i]);
    }
    display3(ptr_stu, entered);
    delete [] ptr_stu;
    cout << "Done\n";
    
    return 0;
}

int getinfo(student pa[], int n)
{
    int i = 0;
    while(cin >> pa[i].fullname >> pa[i].hobby >> pa[i].ooplevel && ++i != n);
    
    return i;
}


void display1(student st)
{
    cout << st.fullname << endl << st.hobby << endl << st.ooplevel << endl << endl;
}

void display2(student * ps)
{
    cout << ps->fullname << endl << ps->hobby << endl << ps->ooplevel << endl << endl;
}

void display3(const student pa[], int n)
{
    for (int i = 0; i != n; i++)
        cout << pa[i].fullname << endl << pa[i].hobby << endl << pa[i].ooplevel << endl << endl;
}
