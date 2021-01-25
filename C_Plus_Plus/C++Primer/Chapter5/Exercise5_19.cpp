#include "INCLUDE.hpp"

int main()
{
    string str1, str2;
    do
    {
        cin >> str1 >> str2;

        cout << "the bigger one is " << (str1 > str2 ? str1 : str2) << endl;

    } while ( str1 != "q" && str2 != "q" );
    
    return 0;
}