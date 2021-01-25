//
//  main.cpp
//  4.11
//
//  Created by 谢逊 on 2020/1/11.
//  Copyright © 2020 谢逊. All rights reserved.
//

#include <iostream>

struct inflatable
{
    char name[20];
    float volume;
    double price;
};

int main()
{
    using namespace std;
    inflatable guest =
    {
        "Glorious Goria",
        1.88,
        29.99
    };
    
    inflatable pal =
    {
        "Audacious Arthur",
        3.12,
        32.99
    };
    
    cout << "Expand your guest list with " << guest.name;
    cout << " and " << pal.name << "!\n";
    cout << "Your can have both for $";
    cout << guest.price + pal.price << ".\n";
    
    return 0;
}
