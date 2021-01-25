#include "INCLUDE.hpp"

void recur_print(vector<int> &vec);

int main()
{
    vector<int> vec = {1,2,3,4,5,6};

    recur_print(vec);

    cout << endl;
}

void recur_print(vector<int> &vec)
{
    static int count = 0;
    cout << vec[count] << "\t";
    if (count++ < vec.size() - 1)
        return recur_print(vec);
}