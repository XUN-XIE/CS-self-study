//
//  Vector.cpp
//  Chapter18
//
//  Created by 谢逊 on 2020/1/20.
//  Copyright © 2020 谢逊. All rights reserved.
//

#include "Vector.hpp"

vector::vector(const vector & arg) : sz{arg.sz}, elem{new double[arg.sz]}
{
    for (int i = 0; i < arg.sz; i++)
        elem[i] = arg.elem[i];
}

vector & vector::operator=(const vector & a)
{
    double * p = new double[a.sz];
    for (int i = 0; i < a.sz; i++)
        elem[i] = a.elem[i];
    delete [] elem;
    elem = p;
    sz = a.sz;
    
    return *this;
}

vector::vector(vector && a) : sz{a.sz}, elem{a.elem}
{
    a.sz = 0;
    a.elem = nullptr;
}

vector & vector::operator=(vector && a)
{
    delete [] elem;
    elem = a.elem;
    sz = a.sz;
    a.elem = nullptr;
    a.sz = 0;
    
    return *this;
}
