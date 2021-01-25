#include "INCLUDE.hpp"

bool search(vector<int> &, int);

int main()
{
    vector<int> targeted = {1,2,3,4,5,6,7,8};
    int target = 10;

    cout << search(targeted, target) << endl;

}

bool search(vector<int> &vec, int num)
{
    auto beg = vec.begin();
    auto end = vec.end();

    while (beg != end)
    {
        if (num == *beg)
            return true;
        beg++;
    }
    return false;
}