#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int interpolate_search(vector<int> & vec, int key)
{
    int lo = 0, hi = vec.size() - 1;
    int found_index;
    int count = 0;
    while (lo <= hi && count < 10)
    {
        count++;
        int mid = lo + (key - lo) / (hi - lo);
        int cmp = key > vec[mid] ?  1 : -1;
        if (key == vec[mid])
            cmp = 0;
        
        cout << lo << "\t" << mid << "\t" << hi << "\t" << cmp << "\t" << vec[mid] << endl;
        if (cmp < 0) hi = mid - 1;
        else if (cmp > 0) lo = mid + 1;
        else
        {
            return mid;
        }
    }
    return lo;
}

int main()
{
    vector<int> vec = {1,2,3,4,10};
    int target = 7;
    auto iter = find(vec.begin(), vec.end(), target);
    cout << (iter - vec.begin()) << endl;

    int index = interpolate_search(vec, target);
    cout << index << endl;
}