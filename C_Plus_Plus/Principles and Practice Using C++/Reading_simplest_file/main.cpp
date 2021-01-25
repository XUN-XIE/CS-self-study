//
//  main.cpp
//  Reading_simplest_file
//
//  Created by 谢逊 on 2020/1/17.
//  Copyright © 2020 谢逊. All rights reserved.
//

//#include <iostream>
//#include <ifsteam>
//#include <ofstream>
//#include <string>
#include "std_lib_facilities.h"
using namespace std;

struct Reading{
    int hour;
    double temperature;
};

int main()
{
    cout << "Please enter input file name: ";
    string image;
    cin >> image;
    ifstream ist{image};
    if (!ist)
        error("can;t open input file ", image);
    
    string oname;
    cout << "Please enter name of output file: ";
    cin >> oname;
    ofstream ost{oname};
    if (!ost)
        error("can't open output file ", oname);
    
    vector<Reading> temps;
    int hour;
    double temperature;
    while (ist >> hour >> temperature)
    {
        if (hour < 0 || hour > 23)
            error ("hour out of range");
        temps.push_back(Reading{hour, temperature});
        
    }
    
    for (int i = 0; i < temps.size(); i++)
        ost << '(' << temps[i].hour << ',' << temps[i].temperature << ")\n";
}
