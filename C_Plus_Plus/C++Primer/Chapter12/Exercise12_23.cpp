#include "INCLUDE.hpp"

int main()
{
    string str1 = "123";
    string str2 = "abc";
    
    size_t length = str1.size() + str2.size();

    char * arr = new char[length];
    for(int i = 0; i != length; i++)
    {
        if (i < 3)
            arr[i] = str1[i];
        else
            arr[i] = str2[i-3];
    }

    delete [] arr;
}