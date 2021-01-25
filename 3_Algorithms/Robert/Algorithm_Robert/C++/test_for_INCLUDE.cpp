#include "INCLUDE.hpp"

// test for my own read file function and output file function
int main()
{
    ifstream infile("dou_infile.txt");
    vector<double> vec = read_data(infile);
    ofstream outfile("dou_outfile.txt");
    // outfile.open("dou_outfile.txt");
    print_to_file(outfile, vec);
}