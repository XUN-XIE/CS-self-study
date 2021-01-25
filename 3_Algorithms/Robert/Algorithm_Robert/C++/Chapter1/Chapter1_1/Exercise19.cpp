#include "INCLUDE.hpp"

long double F(int N);

int main()
{
    for (int N = 0; N < 100; N++)
        cout << N << "\t" << F(N) << endl;
}

long double F(int N)
{
    vector<long double> vec = {0, 1};
    for (int i = 2; i <= N; i++)
        vec.push_back(vec[i-1]+vec[i-2]);
    return vec[N];
}