//
//  complex0.hpp
//  exercise11.7
//
//  Created by 谢逊 on 2020/1/18.
//  Copyright © 2020 谢逊. All rights reserved.
//

#ifndef complex0_hpp
#define complex0_hpp

#include <iostream>

using namespace std;

class complex
{
private:
    double a;
    double b;
public:
    complex();
    complex(double real, double image);
    complex operator~() const;
    complex operator+(const complex & com) const;
    complex operator-(const complex & com) const;
    friend complex operator*(const complex & com1, const complex & com2);
    friend complex operator*(const complex & com, double num);
    friend complex operator*(double num, const complex com)
    { return com * num;}
    
    friend std::ostream & operator<<(std::ostream & os, const complex & com);
    friend std::istream & operator>>(std::istream & is, complex & com);
};


#endif /* complex0_hpp */
