#include "INCLUDE.hpp"

int main()
{
    int i = 3;
    auto func = [&i] () { return i; };

    cout << i << endl;
}