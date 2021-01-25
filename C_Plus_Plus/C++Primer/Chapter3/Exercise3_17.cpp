#include "INCLUDE.hpp"

int main()
{
    vector<string> vec = read_data();

    for (auto &element: vec)
    {
        for (auto &c: element)
            c = toupper(c);
    }
    
    print(vec);

    return 0;
}