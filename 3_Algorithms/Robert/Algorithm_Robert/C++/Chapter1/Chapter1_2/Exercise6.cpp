#include "INCLUDE.hpp"

bool are_rotation(string str1, string str2)
{
    return (str1.size() == str2.size() && str1.append(str1).find(str2) != -1);
} 

int main()
{
    string str1 = "AAACAAA", str2 = "CAAAAAA";
    cout << are_rotation(str1, str2) << endl;
}