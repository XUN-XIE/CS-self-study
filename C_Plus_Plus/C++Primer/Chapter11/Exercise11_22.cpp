#include "INCLUDE.hpp"

int main()
{
    map<string, vector<int>> m;

    pair<map<string, vector<int>>::iterator, bool> iter = m.insert({"xie", vector<int>(1)});
}