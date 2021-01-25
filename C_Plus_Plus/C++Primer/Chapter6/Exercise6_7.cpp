#include "INCLUDE.hpp"

int generate();

int main()
{
    for (int i = 0; i != 10; i ++)
        cout << generate() << "\t";
    cout << endl;

    return 0;
}

int generate()
{
    static int num = 0;

    return num++;
}