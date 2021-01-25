#include "INCLUDE.hpp"

int main()
{
    int par = 10;
    auto sum_10 = [par] (int a) { return a + par; };

    int a = 5;
    cout << sum_10(a) << endl;
}