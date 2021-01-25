#include "../AllSort.hpp"

int main()
{
    for (int size = 1E7; size < 1E8+1; size *= 10)
    {
        vector<int> vec = produce(size);
        test_algorithm(Quick3way, "best one in book  ", size);
        Timer time;
        sort(vec.begin(), vec.end());
        time.elapsedTime("C++ sort algorithm", size);
    }
}