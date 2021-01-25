#include "INCLUDE.hpp"

int main()
{
    istream_iterator<int> item_iter(cin), eof;
    ostream_iterator<int> out_iter(cout, "\t");

    vector<int> vec(item_iter, eof);

    sort(vec.begin(), vec.end());

    copy(vec.begin(), vec.end(), out_iter);

    cout << endl;
}