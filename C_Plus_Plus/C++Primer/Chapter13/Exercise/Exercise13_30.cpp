#include "INCLUDE.hpp"

class HasPtr
{
public:
    HasPtr(const string &s = string()) : ps(new string(s)), i(0) { }
    HasPtr(const HasPtr & other) : ps(new string(*other.ps)), i(other.i) { }
    HasPtr & operator=(const HasPtr & other);
    ~HasPtr() { delete ps; }
    bool operator<(HasPtr & other) { if (i < other.i) return true; else return false; }
    void increment(int n) { i+=n; }
    void get_all() { cout << *ps << " " << i << endl; }
private:
    string *ps; 
    int i;

    friend void swap(HasPtr &, HasPtr &);
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

inline
void swap(HasPtr & lhs, HasPtr & rhs)
{
    using std::swap;
    swap(rhs.ps, lhs.ps);
    swap(lhs.i, rhs.i);
}

int main()
{
    vector<HasPtr> test;
    HasPtr tmp;
    for (int i = 0; i < 10; i++)
    {
        tmp = HasPtr(string(i+1, 'x'));
        tmp.increment(10 - i);
        test.push_back(tmp);
    }
    
    // for (int i = 0; i < 10; i++)
    //     test[i].get_all();
    for (int i = 0; i < 10; i++)
    {
        for (int j = i+1; j < 10 ; j++)
        {
            if (test[j] < test[i])
                swap(test[i], test[j]);
        }
    }

    for (int i = 0; i < 10; i++)
        test[i].get_all();
}