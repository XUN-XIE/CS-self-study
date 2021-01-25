#include "INCLUDE.hpp"

int main()
{
    auto sum = [] (int a, int b) { return a + b; } ;
    
    int a = 1, b = 2;
    cout << sum(1,2) << endl;
}