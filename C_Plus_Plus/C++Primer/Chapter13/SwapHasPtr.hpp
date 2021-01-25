#include <bits/stdc++.h>
using namespace std;

class HasPtr
{
public:
    HasPtr(const string & s = string()) : ps(new string(s)), i(0)   { }
    HasPtr(const HasPtr & other) : ps(new string(*other.ps)), i(other.i) { }

    // technique: copy and swap
    // 注意这里的参数里表中， 没有 const 和 reference
    HasPtr & operator=(HasPtr rhs)
    {
        // swap the contents of the lhs operand with the local variable rhs
        swap(*this, rhs);   // rhs now points to the mempry this object had used
        return *this;       // rhs is destroyed, which deletes the pointer in rhs;
    }

    ~HasPtr()   {   delete ps;  }

    friend void swap(HasPtr &, HasPtr &);
private:
    string *ps;
    int i;
};

inline void swap(HasPtr &lhs, HasPtr &rhs)
{
    using std::swap;
    swap(lhs.ps, rhs.ps);   // swap the pointers, not the string data
    swap(lhs.i, rhs.i);     // swap the int members
}