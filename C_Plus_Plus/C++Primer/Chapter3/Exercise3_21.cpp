#include "INCLUDE.hpp"

int main()
{
    vector<string> vec = read_data();

    cout << vec.size() << endl;

    for (auto index = vec.begin(); index != vec.end(); index++)
        cout << *index << " ";

    cout << endl;

    return 0;
}