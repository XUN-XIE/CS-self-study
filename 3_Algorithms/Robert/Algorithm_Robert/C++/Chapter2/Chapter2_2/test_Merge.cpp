#include "../AllSort.hpp"

int main()
{
    // test_algorithm(MergeSort, "Merge", 100);

    // // test Merge
    // vector<int> vec;
    // for (int i = 0; i < 3; i++)
    //     vec.push_back(50+i);
    // for (int i = 0; i < 3; i++)
    //     vec.push_back(i);
    // Merge(vec, 0, 49, vec.size() - 1);
    // print(vec);

    // // test top-down Merge
    // MergeSort(vec, 0, vec.size() - 1);
    // print(vec);

    // test bottom-up Merge
    // MergeSort(vec);
    // print(vec);

    int size = 1E6;
    test_algorithm(ShellSort, "Shell   ", size);
    test_algorithm(TD_MergeSort, "TD_Merge", size);
    test_algorithm(BU_MergeSort, "BU_Merge", size);
}