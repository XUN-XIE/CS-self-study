#include "INCLUDE.hpp"

class HasPtr
{
public:
    HasPtr(const string &s = string()) : ps(new string(s)), i(0) { }

    // 谨记，只要是constructor，不管是default还是copy的，对于指针成员都要用 new ！！！！
    HasPtr(const HasPtr & other) : ps(new string(*other.ps)), i(other.i) { }
    HasPtr & operator=(const HasPtr & other);
    ~HasPtr() { delete ps; }
private:
    string *ps; 
    int i;
};

HasPtr & HasPtr::operator=(const HasPtr & rhs)
{
    // 重点一：这里用new重新实例化一个对象类型！！！
    string * newp = new string(*rhs.ps);
    delete ps;
    ps = newp;
    // 重点二：newp这个临时变量不能删除！！！因为ps和newp指向的对象是一样的，如果删除，等于ps没有赋值成功


    i = rhs.i;

    return *this;
}

int main()
{
    

}