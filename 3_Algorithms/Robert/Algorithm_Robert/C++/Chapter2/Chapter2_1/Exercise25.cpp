#include "../AllSort.hpp"

int main()
{
    test_algorithm(InsertionSort, "Insertion", 100000);
    test_algorithm(InsertionSort_noex, "Insertion without exchange", 100000);
}