#include "INCLUDE.hpp"

int main()
{
    int arr[10];
    for(int i = 0; i < 10; i++)
        arr[i] = i;

    int arr2[10];
    int i = 0;
    for (auto &ele: arr2)
        ele = arr[i++];
    
    return 0;
}