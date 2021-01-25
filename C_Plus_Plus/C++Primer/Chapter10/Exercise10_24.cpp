#include "INCLUDE.hpp"

bool check_size(const int, size_t val);

int main()
{
    vector<int> vec= {1,2,3,4,5,6,7,8};
    auto first_found = find_if(vec.begin(), vec.end(), bind(check_size, placeholders::_1, 5));

    cout << *first_found << endl;
}

bool check_size(const int num, size_t val)
{
    return num > val;
}