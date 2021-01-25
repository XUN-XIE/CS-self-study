#include "INCLUDE.hpp"

int main()
{
    vector<int> vec = {1,2,3,4,5,6,7,6,5,4,3,2,1};
    print(vec);
    sort(vec.begin(), vec.end());
    print(vec);
    auto end_unique = unique(vec.begin(), vec.end());
    print(vec);
    vec.erase(end_unique, vec.end());
    print(vec);
}