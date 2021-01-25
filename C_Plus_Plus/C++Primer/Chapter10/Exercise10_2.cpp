#include "INCLUDE.hpp"

int main()
{
    vector<string> vec(10, string("a"));

    auto find_iter = find(vec.cbegin(), vec.cend(), "a");
    cout << *find_iter << endl;

    auto count_one = count(vec.cbegin(), vec.cend(), "a");

    cout << count_one << endl;

}