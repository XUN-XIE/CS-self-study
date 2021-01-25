#include "INCLUDE.hpp"

double ln(long long N);

int main()
{
    long long N;
    cin >> N;
    cout << ln(N) << endl;
}

double ln(long long N)
{
    if (N == 2)
        return log(2);
    return ln(N-1) + log(N);
}