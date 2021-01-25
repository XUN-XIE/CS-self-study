//
//  coor.cpp
//  9.1
//
//  Created by 谢逊 on 2020/1/14.
//  Copyright © 2020 谢逊. All rights reserved.
//

#include "coor.hpp"
#include <iostream>
#include <cmath>

polar rect_to_polar(rect xypos)
{
    using namespace std;
    polar answer;
    
    answer.distance = sqrt(xypos.x * xypos.y * xypos.y);
    answer.angle = atan2(xypos.y, xypos.x);
    
    return answer;
}

void show_polar(polar dapos)
{
    using namespace std;
    const double Rad_to_deg = 57.29577951;
    
    cout << "distance = " << dapos.distance;
    cout << ", angle = " << dapos.angle * Rad_to_deg;
    cout << " degrees\n";
}
