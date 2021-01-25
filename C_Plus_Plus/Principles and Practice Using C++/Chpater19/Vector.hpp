//
//  Vector.hpp
//  Chpater19
//
//  Created by 谢逊 on 2020/1/23.
//  Copyright © 2020 谢逊. All rights reserved.
//

#ifndef Vector_hpp
#define Vector_hpp


#include <iostream>
//using namespace std;

class vector
{
    int sz;
    double * elem;
    int space;
public:
    vector() : sz{0}, elem{nullptr}, space{0} {}
    explicit vector(int s) : sz{s}, elem{new double[s]}
    {
        for (int i = 0; i < s; i++)
            elem[i] = 0;
    }
    
    vector(const vector & arg);
    vector & operator=(const vector &);
    
    vector(vector && a);   // move constructor
    vector & operator=(vector &&);  // move assghment
    
    ~vector() { delete [] elem; }

    
    double & operator[](int n) { return elem[n]; }
    const double & operator[](int n) const { return elem[n]; }
    
    int size() const { return sz;}
    int capacity() const { return space; }
    
    void reserve(int newalloc);
    void resize(int newsize);
    void push_back(double d);
    
    
};


#endif /* Vector_hpp */
