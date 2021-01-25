#include "INCLUDE.hpp"

void elimDups(vector<string> &);
bool isShorter(const string &, const string &);

int main()
{
    vector<string> vec = {"xie", "xun", "wan", "yu", "rui"};
    elimDups(vec);

    stable_sort(vec.begin(), vec.end(), isShorter);

    print(vec);

}

void elimDups(vector<string> & words)
{
    sort(words.begin(), words.end());
    auto end_unique = unique(words.begin(), words.end());
    words.erase(end_unique, words.end());
}

bool isShorter(const string & str1, const string & str2)
{
    return str1.size() < str2.size();
}