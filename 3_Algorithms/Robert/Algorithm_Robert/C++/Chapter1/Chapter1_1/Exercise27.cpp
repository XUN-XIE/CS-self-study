#include "INCLUDE.hpp"

double binomial(int N, int k, double p)
{
    vector<vector<double>> vec(N+1);
    vector<double> cols(k+1);
    for (int i = 0; i < N+1; i++)
        vec[i] = cols;

// when N = 0
    for (auto & ele: vec[0])
        ele = 1.0;
    
    for (auto & ele: vec[1])
        ele = 1.0;
    
    

    if ( (N == 0) || (k < 0) )
    {
        return 1.0;
    }
    
    return (1.0 - p) * binomial(N-1, k, p) + p * binomial(N-1, k-1, p);
}

int main()
{
    cout << binomial(10, 7, 0.7) << endl;
}