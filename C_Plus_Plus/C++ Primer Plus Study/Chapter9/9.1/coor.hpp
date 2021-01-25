//
//  coor.hpp
//  9.1
//
//  Created by 谢逊 on 2020/1/14.
//  Copyright © 2020 谢逊. All rights reserved.
//

#ifndef coor_hpp
#define coor_hpp

#include <stdio.h>

struct polar
{
    double distance;
    double angle;
};

struct rect
{
    double x;
    double y;
};

polar rect_to_polar(rect xypos);
void show_polar(polar dapos);

#endif /* coor_hpp */
