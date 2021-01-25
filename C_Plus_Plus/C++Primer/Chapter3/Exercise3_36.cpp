#include "INCLUDE.hpp"


bool equal(int * arr1, int * arr2);
bool equal(vector<int> vec1, vector<int> vec2);

int main()
{
    int arr1[10] ={0,0,0};
    int arr2[10] ={0,0,0};
    int * beg1 = begin(arr1);
    int * end1 = end(arr1);
    int * beg2 = begin(arr2);
    int * end2 = end(arr2);

    bool EQUAL = true;

    if ((end1 - beg1) != (end2 - beg2))
        EQUAL = false;
    
    while (beg1 != end1)
        if (*(beg1++) != *(beg2++))
        {
            EQUAL = false;
            cout << "---" << endl;
            break;
        }
    
    cout << EQUAL << endl;

    return 0;
}

bool equal(int * arr1, int * arr2);

bool equal(vector<int> vec1, vector<int> vec2);