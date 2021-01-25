#include "INCLUDE.hpp"

int main()
{
    vector<int> vec1 = { 1, 2, 3 };
    vector<int> vec2 = { 3 , 2 };

    cout << (vec1 == vec2) << endl;

    list<int> list1 = { 1, 2, 3 };

    auto vec1_iter = vec1.cbegin();
    auto list1_iter = list1.cbegin();
    bool equal = 1;
    while (vec1_iter != vec1.cend() || list1_iter != list1.cend())
        if ( *vec1_iter++ != *list1_iter++)
        {
            equal = 0;
            break;
        }
    cout << equal << endl;
}