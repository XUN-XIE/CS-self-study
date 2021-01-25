#include <bits/stdc++.h>
using namespace std;

class HasPtr
{
public:
    HasPtr(const string & s = string()) : ps(new string(s)), i(0)   { }
    HasPtr(const HasPtr & other) : ps(new string(*other.ps)), i(other.i) { }
    HasPtr & operator=(const HasPtr & rhs)
    {
        // 以下两行这里的顺序很重要！！！
        // 解释：因为 copy assignment 需要确保 rhs 为被赋值对象时的成功赋值
        // 如果先 delete ps，则会导致，新allocate的 tmp中 rhs.ps 为空指针！！！
        string * tmp = new string(*rhs.ps);
        delete ps;
        ps = tmp;

        i = rhs.i;
        return *this;
    }

    ~HasPtr()   {   delete ps;  }
private:
    string *ps;
    int i;
};
