//
//  arraytp.hpp
//  14.17
//
//  Created by 谢逊 on 2020/1/21.
//  Copyright © 2020 谢逊. All rights reserved.
//

#ifndef arraytp_hpp
#define arraytp_hpp

#include <iostream>
#include <cstdlib>

using namespace std;

template <class T, int n>
class ArrayTP
{
private:
    T ar[n];
public:
    ArrayTP() {};
    explicit ArrayTP(const T & v);
    virtual T & operator[](int i);
    virtual T operator[](int i) const;
    
};

template <class T, int n>
T & ArrayTP<T, n>::operator[](int i)
{
    if ( i < 0 || i >= n)
    {
        cerr << "Error in array limits: " << i << " is out of range\n";
        exit(EXIT_FAILURE);
    }
    return ar[i];
}

template <class T, int n>
T ArrayTP<T, n>::operator[](int i) const
{
    if ( i < 0 || i >= n)
    {
        cerr << "Error in array limits: " << i << " is out of range\n";
        exit(EXIT_FAILURE);
    }
    return ar[i];
}
#endif /* arraytp_hpp */
