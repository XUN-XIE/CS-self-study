//
//  stringbad.hpp
//  12.1
//
//  Created by 谢逊 on 2020/1/18.
//  Copyright © 2020 谢逊. All rights reserved.
//

#ifndef stringbad_hpp
#define stringbad_hpp
#include <iostream>
#include <cstring>
using namespace std;

class Stringbad
{
private:
    char * str;
    int len;
    static int num_strings;
public:
    Stringbad(const char * s);
    Stringbad();
    ~Stringbad();
    friend std::ostream & operator<<(std::ostream & os, const Stringbad & st);
};

#endif /* stringbad_hpp */
