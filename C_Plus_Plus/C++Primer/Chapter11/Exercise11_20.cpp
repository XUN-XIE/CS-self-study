#include "INCLUDE.hpp"

int main()
{
    map<string, size_t> word_count;
    set<string> exclude = {"The", "But", "And", "Or", "An", "A", "the", "but", "and", "or", "an", "a"};

    string word;
    while (cin >> word)
    {
        if (exclude.find(word) == exclude.end())
        {
            auto ret = word_count.insert({word, 1});
            if (!ret.second)
                ++((ret.first)->second);
        }
    }

    for (auto &elem: word_count)
        cout << elem.first << "\t" << elem.second << endl;

}