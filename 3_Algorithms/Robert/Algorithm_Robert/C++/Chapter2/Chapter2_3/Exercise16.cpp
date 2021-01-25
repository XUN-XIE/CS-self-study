#include "../AllSort.hpp"

int main()
{
    int size = 1E7;
    test_algorithm(QuickSort, "all distinct", size);
    cout << RAND_MAX << endl;
}