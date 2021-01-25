#include "INCLUDE.hpp"

int main()
{
    int i = 10;

    auto func = [&i] () -> bool
    {   if (i > 0)
        {
            i--;
            return true;
        } else
            return false;
    };

    while(func()) {};
    cout << i << endl;
}