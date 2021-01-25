#include "INCLUDE.hpp"

int main()
{
    vector<int> vec(10,1);

    for (auto index = vec.begin(); index != vec.end(); index++)
        *index *= 2;
    
    print(vec);

    return 0;
}