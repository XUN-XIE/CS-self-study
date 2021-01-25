#include "INCLUDE.hpp"

int main()
{
    map<string, int> m = {{"xie", 1}};
    auto iter = m.begin();
    iter->second = 2;
    cout << m.begin()->second << endl;
}