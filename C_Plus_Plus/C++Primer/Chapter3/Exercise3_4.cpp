#include "INCLUDE.hpp"

int main()
{
    string word1, word2;
    cin >> word1 >> word2;
    decltype(word1.size()) len1 = word1.size();
    decltype(word1.size()) len2 = word2.size();

    if (len1 == len2)
        cout << " Equal length" << endl;

/*
    else
    {
        if (word1 > word2)
            cout << word1;
        else 
            cout << word2;
        cout << " is larger" << endl;
    }
*/

// /*
    else
    {
        if (len1 > len2)
            cout << word1;
        else
            cout << word2;
        cout << " is longer" << endl;
    }
// */
    
    return 0;
}