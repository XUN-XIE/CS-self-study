#include "INCLUDE.hpp"

bool prefix(vector<int> vec1, vector<int> vec2);

int main()
{
    vector<int> vec1 = {1,1,0};
    vector<int> vec2 = {0,1,1,0,1,0};

    cout << prefix(vec1, vec2) << endl;

    return 0;
}

bool prefix(vector<int> vec1, vector<int> vec2)
{
    if (vec1.size() >= vec2.size())
    {
        vector<int> tmp = vec2;
        vec2 = vec1;
        vec1 = tmp;
    }

// so we have that the lenth of vector1 is less or equal to that of second vector
    for (auto ele2 = vec2.begin(); ele2 != vec2.end(); ele2++)
    {
        if (*ele2 == vec1[0])
        {
            for(int i = 1; i < vec1.size(); i++)
            {
                if (*(ele2 + i) != vec1[i])
                    break;
                if (i == vec1.size() - 1)
                    return true;
            }
        }
    }
    return false;
}