#include "INCLUDE.hpp"

vector<string> read_text(string filename);

int main()
{
    string filename = "Exercise8_4.txt";
    vector<string> output = read_text(filename);
    print(output);

    cout << output.size() << endl;
}

vector<string> read_text(string filename)
{
    ifstream in;
    in.open(filename);
    vector<string> total;
    string tmp;
    while (getline(in, tmp))
        total.push_back(tmp);

    return total;
}