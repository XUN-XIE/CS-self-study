#ifndef STRING_HPP
#define STRING_HPP
#include <bits/stdc++.h>
using namespace std;

class String
{
public:
    String (const char * cstr = 0);
    String (const String & str);
    String & operator=(const String & str);
    ~String();

    char * get_c_str() const {  return m_data;  }
private:
    char * m_data;
};

String::String(const char * cstr)
{
    if (cstr)
    {
        // 多处的一个位置放结束符号 '\0'
        m_data = new char[strlen(cstr) + 1];
        strcpy(m_data, cstr);
    }
    else
    {
        m_data = new char[1];
        *m_data = '\0';
    }
}

inline
String::~String()   {   delete m_data;  }

String::String(const String & str)
{
    m_data = new char[strlen(str.m_data) + 1];
    strcpy(m_data, str.m_data);
}

String &
String::operator=(const String & str)
{
    if (this == &str)
        return *this;
    delete [] m_data;
    m_data = new char[strlen(str.m_data) + 1];
    strcpy(m_data, str.m_data);
    return *this;
}


#endif