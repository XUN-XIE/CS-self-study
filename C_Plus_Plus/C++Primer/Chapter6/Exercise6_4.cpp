#include "INCLUDE.hpp"

int fact(int num);

int main()
{
    // Exercise 6.4
    cout << "Enter the number you want to compute:\n";
    int num;
    cin >> num;

    cout << "your result is:\n" << fact(num) << endl;

    return 0;
}

int fact(int num)
{
    int result = 1;
    while (num >= 1)
        result *= num--;

    return result;
}