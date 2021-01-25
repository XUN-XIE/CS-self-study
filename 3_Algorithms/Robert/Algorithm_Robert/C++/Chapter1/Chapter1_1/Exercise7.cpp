#include "INCLUDE.hpp"

int main()
{
    double t = 9.0;
    while ( abs( t - 9.0/t ) > 0.001 )
        t = ( 9.0 / t + t ) / 2.0;
    printf("%.5f\n", t);

    int sum = 0;
    for (int i = 0; i < 1000; i++)
        for (int j = 0; j < i; j++)
            sum++;
    cout << sum << endl;

    sum = 0;
    for (int i = 1; i < 1000; i *= 2)
        for (int j = 0; j < i; j++)
            sum++;
    cout << sum << endl;
}