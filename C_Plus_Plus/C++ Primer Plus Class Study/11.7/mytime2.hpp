//
//  mytime2.hpp
//  11.7
//
//  Created by 谢逊 on 2020/1/18.
//  Copyright © 2020 谢逊. All rights reserved.
//

#ifndef mytime2_hpp
#define mytime2_hpp

#include <stdio.h>

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
    Time operator+(const Time & t) const;
    Time operator-(const Time & t) const;
    Time operator*(double n) const;
    void Show() const;
};
#endif /* mytime2_hpp */
