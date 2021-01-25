//
//  mytime1.hpp
//  11.4
//
//  Created by 谢逊 on 2020/1/18.
//  Copyright © 2020 谢逊. All rights reserved.
//

#ifndef mytime1_hpp
#define mytime1_hpp

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
    void Show() const;
};

#endif /* mytime1_hpp */
