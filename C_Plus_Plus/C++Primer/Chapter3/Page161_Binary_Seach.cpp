#include "INCLUDE.hpp"

int binary_search(vector<int> vec, int sought);

int main()
{
    vector<int> vec;
    for(int i = 0; i < 10; i ++)
        vec.push_back(i);
    
    print(vec);
    cout << binary_search(vec, 2) << endl;
}



int binary_search(vector<int> vec, int sought)
{
    auto beg = vec.begin();
    auto end = vec.end();
    auto mid = vec.begin() + (end - beg) / 2;

    int index = -1;
    while (mid != end)
    {
        cout << *beg << *mid << *end << endl;
        if (sought < *mid)
            end = mid;
        else if (*mid == sought)
        {
            cout << "---------------" << endl;
            return mid - vec.begin();
        }
        else
            beg = mid + 1;
        mid = beg + (end - beg) / 2;
        cout << *beg << *mid << *end << endl;
    }
    cout << *beg << *mid << *end << endl;
    return -1;
}