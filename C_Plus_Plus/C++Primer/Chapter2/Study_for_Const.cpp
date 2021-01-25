#include "INCLUDE.hpp"

int main()
{
    const int v2 = 0;
    int v1 = v2;
    v1 = 3;
    cout <<v1 << endl;

    const int *p2 = &v2;
}