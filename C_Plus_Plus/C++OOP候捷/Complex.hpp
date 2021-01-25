#ifndef COMPLEX_HPP
#define COMPLEX_HPP
#include <bits/stdc++.h>
using namespace std;

template <typename T>
class Complex
{
public:
    Complex(T r = 0, T i = 0) : re(r), im(i) { }
    Complex & operator += (const Complex &);
    T real () const {  return re;  }
    T imag () const {  return im;  }

    // 取反运算符！单目运算。不是相减运算符！
    Complex<T> operator-(const Complex &);
private:
    T re, im;

    friend Complex & __doapl(Complex * ths, const Complex & r);
};


// // 视频版本，使用这个友元函数简化 operator+= 的定义
// // 但是我还不会模版类的友元函数

// // 这样实现的目的是，可能存在类中其他地方需要使用 __doapl 进行Objects的相加！
// // 这段代码是标准库的 complex 类的写法！！！
// template<typename T> inline
// Complex<T> & Complex<T>::__doapl(Complex<T> * ths, const Complex<T> & r)
// {
//     ths->re += r.re;
//     ths->im += r.im;
//     return *ths;
// }

// template <typename T> inline
// Complex<T> & Complex<T>::operator += (const Complex<T> & other)
// {   return __doapl(this, other);    }

// 正常基础版本
template <typename T>
Complex<T> & Complex<T>::operator += (const Complex<T> & other)
{
    re += other.re;
    im += other.im;
    return *this;
}

template <typename T>
Complex<T> Complex<T>::operator - (const Complex<T> & x)
{
    return Complex<T>( - x.re, - x.im );
}

#endif