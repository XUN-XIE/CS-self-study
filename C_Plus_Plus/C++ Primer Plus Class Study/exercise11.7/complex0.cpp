//
//  complex0.cpp
//  exercise11.7
//
//  Created by 谢逊 on 2020/1/18.
//  Copyright © 2020 谢逊. All rights reserved.
//

#include "complex0.hpp"

complex::complex()
{
    a = b = 0.0;
}

complex ::complex(double real, double image)
{
    a = real;
    b = image;
}

complex complex::operator~() const
{
    return complex(a,-b);
}

complex complex::operator+(const complex & com) const
{
    complex temp;
    temp.a = a + com.a;
    temp.b = b + com.b;
    
    return temp;
}

complex complex::operator-(const complex & com) const
{
    complex temp;
    temp.a = a - com.a;
    temp.b = b - com.b;
    
    return temp;
}

complex operator*(const complex & com1, const complex & com2)
{

    return complex(com1.a * com2.a - com1.b * com2.b, com1.a * com2.b + com1.b * com2.a);
}

complex operator*(const complex & com, double num)
{
    return complex(com.a*num, com.b*num);
}

std::ostream & operator<<(std::ostream & os, const complex & com)
{
    os << "(" << com.a << "," << com.b << "i)" << endl;
    
    return os;
}

std::istream & operator>>(std::istream & is, complex & com)
{
    cout << "real: ";
    is >> com.a;
    cout << "imiagniary: ";
    is >> com.b;
    
    return is;
}
