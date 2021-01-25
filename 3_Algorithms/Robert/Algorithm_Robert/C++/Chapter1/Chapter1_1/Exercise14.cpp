#include "INCLUDE.hpp"

int my_lg(int N);

int main()
{
    int N;
    cin >> N;
    cout << (my_lg(N)) << endl;
}

int my_lg(int N)
{
    
    if (N <= 0)
        cerr << "The N must be positive" << endl;
    else if (N >= 2)
    {
        long long count = 1;
        while (count < N)
            count *= 2;
        count /= 2;
        while (count < N)
            count++;
        return --count;
    }

    return 0;
}