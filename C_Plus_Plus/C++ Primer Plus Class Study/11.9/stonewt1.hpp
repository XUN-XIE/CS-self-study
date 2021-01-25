//
//  stonewt1.hpp
//  11.9
//
//  Created by 谢逊 on 2020/1/18.
//  Copyright © 2020 谢逊. All rights reserved.
//

#ifndef stonewt1_hpp
#define stonewt1_hpp

#include <iostream>
using namespace std;

class Stonewt
{
private:
    enum {Lbs_per_stn = 14};
    int stone;
    double pds_left;
    double pounds;
public:
    Stonewt(double lbs);
    Stonewt(int stn, double lbs);
    Stonewt();
    ~Stonewt();
    void show_lbs() const;
    void show_stn() const;
    
    operator int() const;
    operator double() const;
};

#endif /* stonewt1_hpp */
