#include "INCLUDE.hpp"

int main()
{
    int num;
    cin >> num;

    string str;
    for (int n = num; n > 0; n /= 2)
        str = to_string(n % 2) + str;
    
    cout << str << endl;
}