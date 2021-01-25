#include "INCLUDE.hpp"

int main()
{
    vector<int> vec = { 1,2,3,4,5,6};
    auto iter = vec.cend();
    while(iter != vec.cbegin())
        cout << *--iter << " ";
    cout << endl;
}