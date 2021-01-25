#include "INCLUDE.hpp"

int main()
{
    multimap<string, int> mult = {
        {"xie", 1},
        {"xie", 2},
        {"xun", 3},
    };

    auto pair_iter = mult.equal_range("xie");

// 这个删除会改变原始的所有iterator，使其重置，所以不能成功
    // for(auto beg = pair_iter.first; beg != pair_iter.second; beg++)
    //     mult.erase(beg);

    if (pair_iter.first != pair_iter.second)
    // first version
        mult.erase(pair_iter.first, pair_iter.second);
    // second version
        mult.erase(pair_iter.first->first);

    for (auto &ele: mult)
        cout << ele.first << "\t" << ele.second << endl;
}