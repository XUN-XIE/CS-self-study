//
//  mytime0.hpp
//  11.1
//
//  Created by 谢逊 on 2020/1/18.
//  Copyright © 2020 谢逊. All rights reserved.
//

#ifndef mytime0_hpp
#define mytime0_hpp
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
    Time Sum(const Time & t) const;
    void Show() const;
};

#endif /* mytime0_hpp */
