#include "INCLUDE.hpp"

long long gcd(long long p, long long q)
{
    if (q == 0)
        return p;
    long long r = p % q;

    return gcd(q,r);
}


// 留作C++ Primer 的练习，先使用JAVA实现中间的细节
class Rational
{
public:
    Rational(int a, int b) : numerator(a), denominator(b) { }

    // 全部可以用重载运算符实现！！！
    Rational plus(Rational & b);
    Rational operator+(Rational & b);

    Rational minus(Rational & b);
    Rational operator-(Rational & b);

    Rational times(Rational & b);
    Rational operator*(Rational & b);

    Rational divides(Rational & b);
    Rational operator/(Rational & b);

    // 剩下的两个方法不实现，因为C++还没学到运算符重载
    bool operator==(Rational & that);
    ostream & operator<<(ostream & os);

private:
    int numerator;
    int denominator;
};

Rational Rational::plus(Rational & b)
{

}