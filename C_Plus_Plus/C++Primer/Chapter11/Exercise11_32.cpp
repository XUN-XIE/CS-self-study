#include "INCLUDE.hpp"

int main()
{
    multimap<string, int> mult = {
        {"xie", 1},
        {"xie", 2},
        {"xun", 3},
        {"wan", 4},
        {"aaa", 1}
    };

    

    for (auto &ele: mult)
        cout << ele.first << "\t" << ele.second << endl;
}
