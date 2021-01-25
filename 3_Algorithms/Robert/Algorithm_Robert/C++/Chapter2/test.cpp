#include "AllSort.hpp"

int main()
{
    // int size = 1E5;
    // // test_algorithm(SelectionSort, "Selection", size);
    // // test_algorithm(InsertionSort, "Insertion", size);
    // // test_algorithm(ShellSort, "Shell    ", size);

    // double prev_time = 1;
    // double time;
    // for (int i = 10; i < 10 * pow(2,7) + 1; i *= 2)
    // {
    //     time = test_algorithm(InsertionSort, "Insertion", i);
    //     cout << "倍数 " << time/prev_time << endl;
    //     prev_time = time;
    // }
    int size = 1E6;
    test_algorithm(Heapsort, "Heap    ", size);
    // test_algorithm(Quick3way, "best one", size);
    // test_algorithm(MergeSort, "Merge sor", size);
    // test_algorithm(ShellSort, "ShellSort", size);
}