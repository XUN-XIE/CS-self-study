#include "../AllSort.hpp"

int main()
{
    test_algorithm(InsertionSort, "Insertion", 10000);
    test_algorithm(InsertionSort_Sentinel, "Insertion Sentinel", 10000);
}