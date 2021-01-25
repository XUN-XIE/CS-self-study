#include "INCLUDE.hpp"

using int_array = int[4];

int main()
{
    int arr[3][4] = {
        {0,1,2,3},
        {4,5,6,7},
        {8,9,10,11}
    };

// first version: range for
    for (int_array &row: arr)
    {
        for (int ele: row)
            cout << ele << " ";
        cout << endl;
    }

}