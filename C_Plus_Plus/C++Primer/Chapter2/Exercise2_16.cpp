#include <iostream>

int main()
{
    int i = 0, &r1 = i;
    double d = 0, &r2 = d;

    r2 = 3.14159;
    r2 = r1;
    i = r2;
    r1 = d;

    std::cout << i << "\n" << r1 << '\n';
    std::cout << d << "\n" << r2 << '\n';
    return 0;
}