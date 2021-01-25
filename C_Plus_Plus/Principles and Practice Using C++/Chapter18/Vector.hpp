//
//  Vector.hpp
//  Chapter18
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
    explicit vector(int s) : sz{s}, elem{new double[s]}
    {
        for (int i = 0; i < s; i++)
            elem[i] = 0;
    }
    
    ~vector() { delete [] elem; }
    
    vector(const vector & arg);
    vector & operator=(const vector &);
    
    vector(vector && a);   // move constructor
    vector & operator=(vector &&);  // move assghment
//    vector(initializer_list<double> lst) : sz{lst.size()}, elem{new double[sz]}
//    {
//        copy(lst.begin(), lst.end(), elem);
//    }
    
    double & operator[](int n) { return elem[n]; }
    double operator[](int n) const { return elem[n]; }
    
    
    int size() const { return sz;}
    
    double get(int n) const { return elem[n]; }
    void set(int n, double v) { elem[n] = v; }
};


#endif /* Vector_hpp */
