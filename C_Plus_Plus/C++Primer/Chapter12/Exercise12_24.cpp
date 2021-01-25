#include "INCLUDE.hpp"

int main()
{
    string str;
    cin >> str;
    char * arr = new char[str.size()];

    for(int i = 0; i != str.size(); i++)
        arr[i] = str[i];
    
    delete [] arr;
}