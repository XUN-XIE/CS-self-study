#include "../AllSort.hpp"

void Quick3way(vector<int> & vec) {Quick3way(vec, 0, vec.size()-1);}
// 去Allsort.hpp里修改produce函数
int main()
{
    int size = 1E7;
    test_algorithm(QuickSort, "quicksort", size);
    test_algorithm(Quick3way, "Quick3Way", size);
}