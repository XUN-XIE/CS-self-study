#include "INCLUDE.hpp"

int main()
{
    vector<int> vec = { 1,2,3,4,5,6};
    copy(vec.rbegin(), vec.rend(), ostream_iterator<int>(cout, " "));
    cout << endl;
}