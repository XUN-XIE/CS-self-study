#include "INCLUDE.hpp"

long long gcd(long long p, long long q)
{
    if (q == 0)
        return p;
    long long r = p % q;

    return gcd(q,r);
}

int main()
{
    int N = 10;
    vector<vector<bool>> vec(N, vector<bool>(N, 0));

    for(int i = 0; i < N; i++)
        for(int j = 0; j < N; j++)
            vec[i][j] = ( gcd( i>j?i:j , i>j?j:i ) == 1) ? true : false;

    for(int i = 1; i < N; i++)
    {
        for(int j = 0; j < N; j++)
            cout << vec[i][j] << " ";
        cout << endl;
    }

}