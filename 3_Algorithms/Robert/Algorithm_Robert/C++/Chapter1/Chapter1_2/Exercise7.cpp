#include "INCLUDE.hpp"

string mystery(string & s)
{
    int N = s.size();
    if (N <= 1) return s;
    string left = s.substr(0,N/2);
    string right = s.substr(N/2,N - N/2);
    
    return mystery(right) + mystery(left);
}

int main()
{
    string test = "xiexun";

    cout << mystery(test) << endl;
}