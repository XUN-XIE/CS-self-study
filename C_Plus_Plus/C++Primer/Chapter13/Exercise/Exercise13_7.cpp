#include "INCLUDE.hpp"

class HasPtr
{
public:
    HasPtr(const string &s = string()) : ps(new string(s)), i(0) { }
    HasPtr(const HasPtr & other) : ps(new string(*other.ps)), i(other.i) { }
    HasPtr & operator=(const HasPtr & other) { *ps = *other.ps; i = other.i; return *this; }
    ~HasPtr() { delete ps; }
private:
    string *ps; 
    int i;
};

int main()
{
    

}