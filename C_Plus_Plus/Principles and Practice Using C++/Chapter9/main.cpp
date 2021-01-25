//
//  main.cpp
//  Chapter9
//
//  Created by 谢逊 on 2020/1/14.
//  Copyright © 2020 谢逊. All rights reserved.
//

#include <iostream>

using namespace std;

//class X{
//public:
//    int m;
//    int mf(int v) {int old = m; m = v; return old;}
//};
//
//int main()
//{
//    X var;
//    var.m = 7;
//    int x = var.mf(9);
//    cout << x << endl;
//}

// simple Date
//struct Date{
//    int y; // year
//    int m; // month in year
//    int d; // day of month
//};
//
//Date today; // a Date variiable (a named object)
//
//today.y = 2005;
//today.m = 24;
//today.d = 12;
//
//void init_day(Date& dd, int y, int m, int d)
//{
//
//}
//
void add_day(Date& dd, int n)
{

}
//
//void f()
//{
//    Date today;
//    cout << today << '\n';
//
//    init_day(today, 2008, 3, 30);
//
//    Date tomorrow;
//    tomorrow.y = today.y;
//    tomorrow.m = today.m;
//    tomorrow.d = todayd + 1;
//    cout << tomorrow << '\n';
//}

class Date{
public:
    Date(int y, int m, int d);
    void add_day(int n);
    int month();
    
private:
    int y, m, d;
};
