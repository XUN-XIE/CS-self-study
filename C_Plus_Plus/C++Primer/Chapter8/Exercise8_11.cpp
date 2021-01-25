#include "INCLUDE.hpp"

struct PersonInfo
{
    string name;
    vector<string> phones;
};

int main()
{
    string line, word;
    vector<PersonInfo> people;

    istringstream record;
    while (getline(cin, line))
    {
        PersonInfo info;
        record.str(line);
        record >> info.name;
        while (record >> word)
            info.phones.push_back(word);
        people.push_back(info);

        record.clear();
    }


    cout << endl << "print out:\n";
    for (auto & peo: people)
    {
        cout << peo.name << " ";
        print(peo.phones);
    }
}