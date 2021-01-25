#include "INCLUDE.hpp"

int main()
{
    ifstream file("/Users/xiexun/Downloads/C_Plus_Code/Chapter10/Exercise10_33.txt");
    ofstream out_file1("odd_number.txt");
    ofstream out_file2("even_number.txt");

    istream_iterator<int> item_iter(file), eof;

    ostream_iterator<int> out_iter1(out_file1, " ");
    ostream_iterator<int> out_iter2(out_file2, " ");


    vector<int> vec(item_iter, eof);
    auto beg = vec.cbegin();
    while(beg != vec.cend())
    {
        if( (*beg) % 2 == 1)
            *out_iter1++ = *beg;
        else
            *out_iter2++ = *beg;
        beg++;
    }


}
