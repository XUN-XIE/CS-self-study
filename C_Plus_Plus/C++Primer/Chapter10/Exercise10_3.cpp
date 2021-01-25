#include "INCLUDE.hpp"

int main()
{
    vector<int> vec = {1,2,3,4,5,6,7,6,5,4,3,2,1};

    cout << accumulate(vec.cbegin(), vec.cend(), 0) << endl;

}