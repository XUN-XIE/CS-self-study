#include "INCLUDE.hpp"

int abs(int num);

int main()
{
    cout << "Enter the nummber you want to compute absolute" << endl;
    int num;
    cin >> num;

    cout << "your result is:\n" << abs(num) << endl;

    return 0;
}

int abs(int num)
{
    if (num >= 0)
        return num;
    else
        return -num;
}