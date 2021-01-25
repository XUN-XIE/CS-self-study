//
//  studentc.hpp
//  14.1
//
//  Created by 谢逊 on 2020/1/21.
//  Copyright © 2020 谢逊. All rights reserved.
//

#ifndef studentc_hpp
#define studentc_hpp

#include <iostream>
#include <string>
#include <valarray>

using namespace std;

class Student
{
private:
    typedef valarray<double> Arraydb;
    string name;
    Arraydb scores;
    ostream & arr_out(ostream & os) const;
public:
    Student() : name("Null Student"), scores() {}
    explicit Student(const string & s) : name(s), scores() {}
    explicit Student(int n) : name("Null Student"), scores(n) {}
    Student (const string & s, int n) : name(s), scores(n) {}
    Student (const string & s, const Arraydb & a) : name(s), scores(a) {}
    Student (const char * str, const double * pd, int n) : name(str), scores(pd, n) {};
    
    ~Student() {}
    double Average() const;
    double & operator[] (int i);
    double operator[] (int i) const;
    
    friend istream & operator>>(istream & is, Student & stu);
    friend istream & getline(istream & is, Student & stu);
    
    friend ostream & operator<<(ostream & os, Student & stu);
};

#endif /* studentc_hpp */
