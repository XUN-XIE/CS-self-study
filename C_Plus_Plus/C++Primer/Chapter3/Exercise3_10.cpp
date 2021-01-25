#include "INCLUDE.hpp"

int main()
{
    string str;
    getline(cin, str);
    string output;

    for (auto c: str)
        if(!ispunct(c))
            output += c;
    
    cout << output << endl;

    return 0;
}