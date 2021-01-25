#include "INCLUDE.hpp"

bool bigger_five(const string & str);

int main()
{
    vector<string> vec = {"xie", "xun", "xiexun", "xiewa", "wan", "rui","wanrui"};
    
    auto end_iter = partition(vec.begin(), vec.end(), bigger_five);

    auto beg_iter = vec.cbegin();
    while (beg_iter != end_iter)
        cout << *beg_iter++ << "\t";
    cout << endl;
}

bool bigger_five(const string & str)
{
    return str.size() >= 5;
}