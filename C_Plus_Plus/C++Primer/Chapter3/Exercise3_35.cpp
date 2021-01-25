#include "INCLUDE.hpp"

int main()
{
    int arr[10];
    int * beg = std::begin(arr);
    int * end = std::end(arr);

    for(auto i = beg; i < end; i++)
        *i = 0;

    return 0;
}