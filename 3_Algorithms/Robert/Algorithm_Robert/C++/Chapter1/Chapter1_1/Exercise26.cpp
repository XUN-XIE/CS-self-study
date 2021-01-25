#include "INCLUDE.hpp"

int main(int argc, char* argv[])
{
    int a = stoi(string(argv[1])), b = stoi(string(argv[2])), c = stoi(string(argv[3]));

    int t;
    if (a > b)
    {   
        t = a;
        a = b;
        b = t;
    }

    if (a > c)
    {
        t = a;
        a = c;
        c = t;
    }

    if (b > c)
    {
        t = b;
        b = c;
        c = t;
    }

    cout << a << "\t" << b << "\t" << c << endl;
}