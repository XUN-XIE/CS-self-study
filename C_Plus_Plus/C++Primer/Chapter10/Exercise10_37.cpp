#include "INCLUDE.hpp"

int main()
{
    vector<int> vec = {0,1,2,3,4,5,6,7,8,9};
    list<int> target_list;
    copy(vec.rbegin() + 3, vec.rend() - 3, back_inserter(target_list));

    copy(target_list.begin(), target_list.end(), ostream_iterator<int>(cout, " "));
}