#include "INCLUDE.hpp"

int mystery(int a, int b);

int main()
{
    int num1 = mystery(2, 25), num2 = mystery(3, 11);

    cout << num1 <<endl;
    cout << num2 << endl;
}

int mystery(int a, int b)
{
    if (b==0)
        return 0;
    if (b % 2 == 0)
        return mystery(a+a, b/2);
    return mystery(a+a, b/2) + a;
}