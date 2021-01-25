#include "../AllSort.hpp"

int count_duplicate(vector<int> & vec)
{
    int count = 0;
    for (int i = 0; i < vec.size() - 1; i++)
        if(vec[i] == vec[i+1])
            count++;
    return count;
}

int main()
{
    int trial = 10;
    

    for (int N = 1E3; N < 1E6 + 1; N *= 10)
    {
        for (int M = N / 2; M < 2 * N + 1; M *= 2)
        {
            double count = 0;
            for (int t = 0; t < trial; t++)
            {
                vector<int> vec = produce(N, M);
                Quick3way(vec);
                count += count_duplicate(vec);
                
            }
            count /= trial;
            double tmpN = N;
            double alpha = tmpN / M;
            double ratio = 1 - exp(-alpha);
            printf("size: %d\t range: %d\t ratio: %f\t  real ratio: %f\t\n", N, M, ratio, count / N);
        }
    }

}