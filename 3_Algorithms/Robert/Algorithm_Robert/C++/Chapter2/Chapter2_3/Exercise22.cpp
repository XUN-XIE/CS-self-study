#include "../AllSort.hpp"

int main()
{
    int size = 1E7;
    test_algorithm(Fast3way, "fast3way", size);
    test_algorithm(QuickSort, "original", size);
    test_algorithm(Quick3way, "updated", size);
}