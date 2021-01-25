#include "RedBlackBST.hpp"

int main()
{
    RedBlackBST<int, int> rbbst;
    for (int i = 0; i < 1E1; i++)
        rbbst.put(rand()%10, i);
    rbbst.levelOrder();
    // // rbbst.preorder();
    // // for (int i = 0; i < 9; i++)
    // rbbst.deleteMin();
    // rbbst.levelOrder();
    // rbbst.preorder();
        // rbbst.deleteMin();
        // rbbst.deleteMin();
        // rbbst.deleteMax();
        rbbst.deleteKey(2);
        rbbst.levelOrder();
    // for (int i = 0; i < 1E4; i++)
    // {
    //     rbbst.deleteKey(rand());
    //     rbbst.put(rand(), 1);
    // }
}