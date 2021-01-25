#include "INCLUDE.hpp"

int main()
{
    vector<int> vec;

    fill_n(back_inserter(vec), 10, 0);

    print(vec);
}