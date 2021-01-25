//
//  main.cpp
//  7.12
//
//  Created by 谢逊 on 2020/1/15.
//  Copyright © 2020 谢逊. All rights reserved.
//

#include <iostream>

#include <cmath>

using namespace std;

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


int main()
{
    rect rplace;
    polar pplace;
    
    cout << "Enter the x and y values: ";
    
    while (cin >> rplace.x >> rplace.y)
    {
        pplace = rect_to_polar(rplace);
        show_polar(pplace);
        cout << "Next two numbers (q to quit): ";
    }
    cout << "Byes!\n";
    
    return 0;
}



polar rect_to_polar(rect xypos)
{
    using namespace std;
    polar answer;
    
    answer.distance = sqrt(xypos.x * xypos.x + xypos.y * xypos.y);
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
