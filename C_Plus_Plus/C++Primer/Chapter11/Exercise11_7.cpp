#include "INCLUDE.hpp"

int main()
{
    map<string, vector<string>> names;

    string family_name;
    while(cin >> family_name)
    {
        string first_name;
        cin >> first_name;
        names[family_name].push_back(first_name);
    }

    for(auto const &names : names)
    {
        cout << "For fimaly " << names.first << " :" << endl;
        print(names.second);
    }

}