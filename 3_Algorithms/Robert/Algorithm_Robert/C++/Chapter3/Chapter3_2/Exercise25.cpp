#include "BinarySearchTree.hpp"

void perfect(BST<int, int> & bst, vector<int> a, int low, int high)
{
    if (high < low) return;
    int mid = (high + low) / 2;
    bst.put(a[mid], mid);
    perfect(bst, a, low, mid - 1);
    perfect(bst, a, mid + 1, high);
}

void perfect(BST<int, int> & bst, vector<int> a)
{
    sort(a.begin(), a.end());
    perfect(bst, a, 0, a.size() - 1);
}

vector<int> produce(long long size, long long max = -1)
{
    srand(0);
    vector<int> vec(size);
    if (max > 0)
    {
        for (int i = 0; i < size; i++)
        vec[i] = rand() % max;
    }
    else
    {
        for (int i = 0; i < size; i++)
        vec[i] = rand();
    }
    return vec;
}

// size不要太大，这个运行很慢！！！
int main()
{
    vector<int> vec = produce(1E4, 100);
    BST<int, int> bst;
    perfect(bst, vec);
    cout << bst.size() << endl;
    cout << bst.height(bst.max());
}