//
//  Vector.cpp
//  Chpater19
//
//  Created by 谢逊 on 2020/1/23.
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
    if (this == &a)
        return *this;
    
    if (a.sz <= space)
    {
        for (int i = 0; i < a.sz; i++)
            elem[i] = a.elem[i];
        sz = a.sz;
        
        return *this;
    }
    
    double * p = new double[a.sz];
    for (int i = 0; i < a.sz; i++)
        elem[i] = a.elem[i];
    delete [] elem;
    elem = p;
    space = sz = a.sz;
    
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



void vector::reserve(int newalloc)
{
    if (newalloc <= space)
        return;
    double * p = new double[newalloc];
    for (int i = 0; i < sz; i++)
        p[i] = elem[i];
    delete [] elem;
    elem = p;
    space = newalloc;
}


void vector::resize(int newsize)
{
    reserve(newsize);
    for( int i = sz; i < newsize; i++ )
        elem[i] = 0;
    sz = newsize;
}

void vector::push_back(double d)
{
    if (space == 0)
        reserve(8);
    else if (sz == space)
        reserve(2*space);
    elem[sz] = d;
    ++sz;
}


