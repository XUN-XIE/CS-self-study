#include "INCLUDE.hpp"

int main()
{
    map<string, int> word_count = {
        {"xie", 1},
        {"xun", 2},
        {"wan", 3},
    };
    map<string, int>::const_iterator map_it = word_count.cbegin();
    while (map_it != word_count.cend())
    {
        cout << map_it->first << " occurs " << map_it->second << " times" << endl;
        ++map_it;
    }
}