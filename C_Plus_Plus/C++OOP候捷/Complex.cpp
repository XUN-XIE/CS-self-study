#include "Complex.hpp"

int main()
{
    // 这里是一个知识点，如果是const类型的Object，只可以调用加const的member fucntions
    const Complex<double> test(0,0);
    cout << test.real() << endl;

    Complex<double> test1(1,2);
    Complex<double> test2(3,4);
    test1 += test2;
    cout << test1.imag() << endl;
    cout << (-test1.imag()) << endl;
}