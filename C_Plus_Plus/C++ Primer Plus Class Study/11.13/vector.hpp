//
//  vector.hpp
//  11.3
//
//  Created by 谢逊 on 2020/1/18.
//  Copyright © 2020 谢逊. All rights reserved.
//

#ifndef vector_hpp
#define vector_hpp

#include <stdio.h>
#include <ostream>
#include <iostream>
#include <cmath>

namespace VECTOR
    {
    class Vector
    {
    public:
        enum Mode {RECT, POL};
    private:
        double x;
        double y;
        double mag;
        double ang;
        Mode mode;
        void set_mag();
        void set_ang();
        void set_x();
        void set_y();
    public:
        Vector();
        Vector(double n1, double n2, Mode form = RECT);
        void reset(double n1, double n2, Mode form = RECT);
        ~Vector();
        double xval() const {return x;}
        double yval() const {return y;}
        double magval() const {return mag;}
        double angval() const {return ang;}
        
        void polar_mode();
        void rect_mode();
        
        Vector operator+(const Vector & b) const;
        Vector operator-(const Vector & b) const;
        Vector operator-() const;
        Vector operator*(double n) const;
        
        friend Vector operator*(double n, const Vector & a) { return a * n; }
        friend std::ostream & operator<<(std::ostream & os, const Vector & v);
    };
    }

#endif /* vector_hpp */
