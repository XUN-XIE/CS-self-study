//
//  main.cpp
//  7.13
//
//  Created by 谢逊 on 2020/1/15.
//  Copyright © 2020 谢逊. All rights reserved.
//

#include <iostream>

#include <iostream>

using namespace std;

struct travel_time
{
    int hours;
    int mins;
};


const int Mins_per_hr = 60;

travel_time * sum(travel_time * t1, travel_time * t2);
void show_time(const travel_time * t);

int main()
{
    travel_time day1 = {5, 45};
    travel_time day2 = {4, 55};
    
    travel_time * trip = sum(&day1, &day2);
    cout << "Two day: ";
    show_time(trip);
    
    travel_time day3 = {4, 32};
    cout << "Three day total: ";
    show_time(sum(trip, &day3));
    
    return 0;
}

travel_time * sum(travel_time * t1, travel_time * t2)
{
    travel_time * total = new travel_time;
    
    total->mins = (t1->mins + t2->mins) % Mins_per_hr;
    total->hours = t1->hours + t2->hours + (t1->mins + t2->mins) / Mins_per_hr;
    
    return total;
}

void show_time(const travel_time * t)
{
    cout << t->hours << " hours, " << t->mins << " minutes\n";
}
