#include "INCLUDE.hpp"

vector<string> read_text(string filename);
void write_out(string filename, vector<string> &);

int main()
{
    string filename = "Exercise8_4.txt";
    vector<string> output = read_text(filename);
    // print(output);

    // cout << output.size() << endl;

    string output_file = "Exercise8_5.txt";
    write_out(output_file, output);
}

vector<string> read_text(string filename)
{
    ifstream in;
    in.open(filename);
    vector<string> total;
    string tmp;
    while (in >> tmp)
        total.push_back(tmp);

    return total;
}

void write_out(string filename, vector<string> & target)
{
    ofstream out(filename, ofstream::app);
    if (out)
    {
        string tmp;
        auto last_ele = target.end();
        while (out << *(--last_ele) && last_ele != target.begin())
        {}

    }
}
