#include "StringSort.hpp"

void print(vector<string> & vec)
{
    for (int i = 0; i < vec.size(); i++)
        cout << vec[i] << " ";
    cout << endl;
}

vector<string>
readIn()
{
    ifstream infile;
    infile.open("./words3.txt");

    vector<string> StringVec;
    string word;
    while (infile >> word)
        StringVec.push_back(word);
    return StringVec;
}

int main()
{
    vector<string> StringVec = readIn();

    print(StringVec);

    // LSDsort(StringVec);
    // MSD msd{};
    // msd.Sort(StringVec);
    Quick3Sort(StringVec);
    print(StringVec);
}