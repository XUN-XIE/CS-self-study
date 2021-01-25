#include "BinarySearchTree.hpp"

int main()
{
    int trials = 10;
    for(int size = 1E4; size < 1E6 + 1; size *= 10)
    {
        double count_height = 0;
        for (int trial = 0; trial < trials; trial++)
        {
            BST<int, int> bst;
            for(int i = 0; i < size; i++)
                bst.put(rand(), 1);
            count_height += bst.height(bst.max());
        }
        double average = count_height / trials;
        cout << "size is " << size << "\t\t height is " << average << "\t theory height is : " << 2.99 * log(size) << endl;
    }
}