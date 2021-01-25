#include "../AllSort.hpp"

int main()
{
    for (int size = 1E3; size <= 1E8 + 1; size *= 10)
    {
        test_algorithm(TD_MergeSort, "TD", size);
        test_algorithm(BU_MergeSort, "BU", size);
    }
}