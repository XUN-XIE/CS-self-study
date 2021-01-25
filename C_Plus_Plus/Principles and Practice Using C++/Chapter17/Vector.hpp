//
//  Vector.hpp
//  Chapter17
//
//  Created by 谢逊 on 2020/1/20.
//  Copyright © 2020 谢逊. All rights reserved.
//

#ifndef Vector_hpp
#define Vector_hpp

#include <iostream>
using namespace std;

class vector
{
    int sz;
    double * elem;
public:
    vector(int s) : sz{s}, elem{new double[s]}
    {
        for (int i = 0; i < s; i++)
            elem[i] = 0;
    }
    
    ~vector() { delete [] elem; }
    int size() const { return sz;}
    
    double get(int n) const { return elem[n]; }
    void set(int n, double v) { elem[n] = v; }
};



#endif /* Vector_hpp */
