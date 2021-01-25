#include "INCLUDE.hpp"

int main()
{
    bool arrays[10][10];
    for (int i = 0; i < 10; i++)
        for (int j = 0; j < 10; j++)
            arrays[i][j] = (i+j) % 2;
    
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
            cout << arrays[i][j] << "\t";
        cout << endl;
    };

}