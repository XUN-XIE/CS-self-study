#include "../AllSort.hpp"

int main()
{
    double prev_time = 1;
    double time;
    for (int i = 10; i < 10 * pow(2,12) + 1; i *= 2)
    {
        time = test_algorithm(InsertionSort, "Insertion", i);
        cout << "倍数 " << time/prev_time << endl;
        prev_time = time;
    }
}