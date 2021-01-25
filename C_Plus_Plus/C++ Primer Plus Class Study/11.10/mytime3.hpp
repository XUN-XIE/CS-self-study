//
//  mytime3.hpp
//  11.10
//
//  Created by 谢逊 on 2020/1/18.
//  Copyright © 2020 谢逊. All rights reserved.
//

#ifndef mytime3_hpp
#define mytime3_hpp

#include <iostream>
#include <stdio.h>
using std::cout;

class Time{
private:
    int hours;
    int minutes;
public:
    Time();
    Time(int h, int m = 0);
    void Addmin(int m);
    void Addhr(int h);
    void Reset(int h = 0, int m = 0);
    friend Time operator+(const Time & t1, const Time & t2);
    friend Time operator-(const Time & t1, const Time & t2);
    friend Time operator*(const Time & t, double n);
    friend Time operator*(double m, const Time & t)
    { return t * m; }
    friend std::ostream & operator<<(std::ostream & os, const Time & t);
};

#endif /* mytime3_hpp */
