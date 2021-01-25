#include "INCLUDE.hpp"

// vector<int> readInts(string filename)
// {
//     ifstream infile(filename);
//     istream_iterator<int> in_iter(infile), eof;

//     return vector<int>(in_iter, eof);
// }

// vector<double> readDoubles(string filename)
// {
//     ifstream infile(filename);
//     istream_iterator<double> in_iter(infile), eof;

//     return vector<double>(in_iter, eof);
// }

int main()
{
    vector<int> vec = readInts("jobsPC.txt");
    print(vec);
}