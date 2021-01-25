#include "INCLUDE.hpp"

int main()
{
    string str;
    vector<string> all_words;
    vector<unsigned int> counts;
    bool noFound;

    string old_str;

    while (cin >> str)
    {
        if (old_str == str)
            break;
        noFound = true;
        for (int i = 0; i < all_words.size(); i++)
        {
            if (all_words[i] == str)
            {
                counts[i]++;
                noFound = false;
            }
        }
        
        if (noFound)
        {
            all_words.push_back(str);
            counts.push_back(1);
        }
        old_str = str;
    }

// find the biggest number in counts;
    decltype(counts.size()) max_index = 0;
    for (decltype(counts.size()) i = 0; i < counts.size(); i++)
    {
        if (counts[i] > counts[max_index])
        {
            cout << counts[i] << endl;
            max_index = i;
        }
    }

    if (counts[max_index] == 1)
        cout << "no words was repeated!" << endl;
    else
        cout << all_words[max_index] << " occurred " << counts[max_index] << " times!" << endl;

    return 0;
}
