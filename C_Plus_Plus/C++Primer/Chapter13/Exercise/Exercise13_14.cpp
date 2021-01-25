#include "INCLUDE.hpp"

class numbered
{
public:
    numbered() { mysn = 0; }
    numbered(const numbered & other) { mysn = other.mysn + 1; }
    numbered & operator=(const numbered & other) { mysn = other.mysn; return *this; }
    int mysn;
};

// // copy initialization
// void f(numbered s)
// {
//     cout << s.mysn << endl;
// }

// mysn没有加一，为什么？？？
void f(const numbered & s)
{
    cout << s.mysn << endl;
}

int main()
{
    // 对于b,c 在定义时赋值 其实是 copy initialization
    numbered a, b = a, c = b;

    // 这种情况才是 copy assignment
    // b = a;
    // c = b;
    
    cout << a.mysn << " " << b.mysn << " " << c.mysn << endl;
    f(a); f(b); f(c);
}