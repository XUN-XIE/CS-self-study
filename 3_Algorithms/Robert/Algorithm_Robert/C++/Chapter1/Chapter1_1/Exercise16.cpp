#include "INCLUDE.hpp"

string exR1(int n);

int main()
{
    string str = exR1(6);
    cout << str << endl;
}

string exR1(int n)
{
    if ( n <= 0)
        return "";
    return exR1(n-3) + exR1(n-2) + to_string(n);
}