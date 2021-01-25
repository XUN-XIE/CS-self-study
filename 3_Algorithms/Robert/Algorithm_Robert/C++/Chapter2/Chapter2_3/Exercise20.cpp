#include "../AllSort.hpp"

void nonrecursive_Quicksort(vector<int> & vec)
{
    stack<int> stk;
    stk.push(0);
    stk.push(vec.size()-1);
    while (!stk.empty())
    {
        int high = stk.top(); stk.pop();
        int low = stk.top(); stk.pop();

        if (low >= high) continue;

        int mid = partition(vec, low, high);
        stk.push(low);
        stk.push(mid - 1);
        stk.push(mid + 1);
        stk.push(high);
    }
}

int main()
{
    int size = 1E7;
    test_algorithm(nonrecursive_Quicksort, "non recursive", size);
    test_algorithm(QuickSort, "recursive", size);
}