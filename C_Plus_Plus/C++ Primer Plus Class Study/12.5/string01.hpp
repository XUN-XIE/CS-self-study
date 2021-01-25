//
//  string01.hpp
//  12.5
//
//  Created by 谢逊 on 2020/1/18.
//  Copyright © 2020 谢逊. All rights reserved.
//

#ifndef string01_hpp
#define string01_hpp

#include <iostream>
#include <cstring>
using namespace std;

class String
{
private:
    char * str;
    int len;
    static int num_strings;
    static const int CINLIM = 80;
public:
    String(const char * s);
    String();
    String(const String &);
    ~String();
    
    int length () const { return len; }
    String & operator=(const String &);
    String & operator=(const char *);
    char & operator[] (int i);
    const char & operator[] (int i) const;
    
    friend bool operator<(const String & st, const String &st2);
    friend bool operator>(const String & st, const String &st2);
    friend bool operator==(const String &st, const String &st2);
    friend ostream & operator<<(ostream & os, const String & st);
    friend istream & operator>>(istream & is, String & st);
    
    static int Howmany();
};

#endif /* string01_hpp */
