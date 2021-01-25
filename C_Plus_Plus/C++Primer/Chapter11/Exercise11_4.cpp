#include "INCLUDE.hpp"

int main()
{
    map<string, size_t> word_count;
    set<string> exclude = {"the", "but", "and", "or", "an", "a"};

    string word;
    while (cin >> word)
    {
        for (auto & c: word)
            c = tolower(c);
        if (exclude.find(word) == exclude.end())
            ++word_count[word];
    }

    for (auto &elem: word_count)
        cout << elem.first << "\t" << elem.second << endl;

}