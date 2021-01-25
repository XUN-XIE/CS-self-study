//
//  main.cpp
//  5.20
//
//  Created by 谢逊 on 2020/1/14.
//  Copyright © 2020 谢逊. All rights reserved.
//

#include <iostream>

const int Cities = 5;
const int Years = 4;

int main()
{
    using namespace std;
    
    const char * cities[Cities] =
    {
        "Gribble City",
        "Gribbletown",
        "New Gribble",
        "San Gribble",
        "Gribble Vista"
    };
    
    *cities = "xiexun";
    
    int maxtemps[Years][Cities] =
    {
        {96, 100, 87, 101, 105},
        {96, 98, 91, 107, 104},
        {97, 101, 93, 108, 107},
        {98, 103, 95, 109, 108}
    };
    
    cout << "Maximum temperatures for 2008 - 2011\n\n";
    
    for (int city = 0; city < Cities; ++city)
    {
        cout << cities[city] << ":\t";
        for (int year = 0; year < Years; ++year)
            cout << maxtemps[year][city] << "\t";
        cout << endl;
    }
    
    return 0;
}
