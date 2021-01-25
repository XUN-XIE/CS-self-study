#include "INCLUDE.hpp"

int main()
{
    vector<int> vec = {1,1,2,2,3,3,4,4,5,5,4,3,2,1};
    list<int> target_list;
    sort(vec.begin(), vec.end());
    unique_copy(vec.begin(), vec.end(), inserter(target_list, target_list.begin()));

    auto iter = target_list.begin();
    while(iter != target_list.end())
        cout << *iter++ << "\t";
    cout << endl;
}