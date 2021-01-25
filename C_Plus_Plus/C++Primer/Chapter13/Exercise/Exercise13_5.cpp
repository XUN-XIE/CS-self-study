#include <bits/stdc++.h>
using namespace std;

class HasPtr
{
public:
    HasPtr(const string & s = string()) : ps(new string(s)), i(0)   { }
    HasPtr(const HasPtr & other)
    {
        i = other.i;
        ps = new string(*other.ps);
    }

    HasPtr & operator=(const HasPtr & rhs) = delete;
    // {
    //     string * tmp = new string(*rhs.ps);
    //     delete ps;
    //     ps = tmp;

    //     i = rhs.i;
    //     return *this;
    // }

    ~HasPtr()   {   delete ps;  }
private:
    string *ps;
    int i;
};

int main()
{
    HasPtr a("xiexun");
    HasPtr b(a);
    HasPtr c(" ");
    // c = a;
    cout << NULL << " " << nullptr << endl;
}