#include "INCLUDE.hpp"

int main()
{
    vector<int> vec = {1,2,3,4,5,6,7,6,5,4,3,2,1};

    auto find_iter = find(vec.cbegin(), vec.cend(), 4);
    cout << *find_iter << endl;

    auto count_one = count(vec.cbegin(), vec.cend(), 1);

    cout << count_one << endl;

}