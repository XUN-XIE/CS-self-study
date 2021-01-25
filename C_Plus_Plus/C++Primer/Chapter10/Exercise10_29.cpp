#include "INCLUDE.hpp"

int main()
{
    ifstream file("/Users/xiexun/Downloads/C_Plus_Code/Chapter10/Exercise10_29.txt");
    
    istream_iterator<string> item_iter(file), eof;
    ostream_iterator<string> out_iter(cout, "\t");

    vector<string> vec(item_iter, eof);

    copy(vec.begin(), vec.end(), out_iter);
}
