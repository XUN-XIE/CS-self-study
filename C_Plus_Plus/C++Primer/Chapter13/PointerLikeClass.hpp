#include <bits/stdc++.h>
using namespace std;

class HasPtr
{
public:
    HasPtr(const string & s = string()) : ps(new string(s)), i(0), use(new size_t(1))   { }
    HasPtr(const HasPtr & other) : ps(other.ps), i(other.i), use(other.use) {   ++*use; }
    HasPtr & operator=(const HasPtr & rhs)
    {
        ++*rhs.use;     // increment the use count of the right-hand operand

        // 这个操作意思是，lhs的object只剩下这一个在使用这一系列的class时，删除它包含的两个指针
        // 所以 如书中所说，act like deconstructor 
        // 不能使用deconstructor自动删除这个原来的object， 因为这个object被赋值为另一个class了！
        if (--*use == 0)    // then decrement this objects's counter
        {
            delete ps;      // if no other users
            delete use;     // free this objets's allocated members
        }
        ps = rhs.ps;        // copy data from rhs into this object
        i = rhs.i;
        use = rhs.use;
        return *this;       // return this object
    }

    ~HasPtr()
    {
        if (--*use == 0)    // if the reference count goes to 0
        {
            delete ps;      // delete the string
            delete use;     // and the counter
        }
    }
private:
    string *ps;
    int i;
    size_t *use;    // member to keep track of how many objects share *ps
};
