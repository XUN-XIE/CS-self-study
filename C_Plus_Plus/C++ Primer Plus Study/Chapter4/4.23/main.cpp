//
//  main.cpp
//  4.23
//
//  Created by 谢逊 on 2020/1/12.
//  Copyright © 2020 谢逊. All rights reserved.
//

#include <iostream>
using namespace std;

struct antarctiica_years_end
{
    int year;
};

int main()
{
    antarctiica_years_end s01, s02, s03;
    s01.year = 1998;
    antarctiica_years_end * pa = &s02;
    pa->year = 1999;
    antarctiica_years_end trio[3];
    trio[0].year = 2003;
    cout << trio->year << endl;
    const antarctiica_years_end * arp[3] = {&s01, &s02, &s03};
    cout << arp[1]->year << endl;
    const antarctiica_years_end ** ppa = arp;
    auto ppb = arp;
    cout << (*ppa)->year << endl;
    cout << (*(ppb+1))->year << endl;
    
    return 0;
}
