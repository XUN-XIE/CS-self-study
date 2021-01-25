#include "BinarySearchTree.hpp"

// this is the test case for my BinarySearchTree
// Exercise 10
//////////////////////////////////////////////////////////////
int main()
{
    BST<char, int> bst;
    string test_str = "SEARCHEXAMPLE";
    for (int i = 0; i < test_str.size(); i++)
        bst.put(test_str[i], i);
    
    bst.preorder();
    bst.levelOrder();

    // test get('A') = 8
    assert (bst.get('A') == 8);
    // test get('W') = -1   not found
    assert (bst.get('W') == -1);

    // // test height for Exercise 6
    // cout << bst.height('A') << endl;

    // test min() = 'A'
    assert (bst.min() == 'A');
    // test max() = 'X'
    assert (bst.max() == 'X');

    // test floor('E') = 'E'
    // test ceiling('E') = 'E'
    assert (bst.floor('E') == 'E');
    assert (bst.ceiling('E') == 'E');
    // test floor('B') = 'A'
    // test ceiling('B') = 'C'
    assert (bst.floor('B') == 'A');
    assert (bst.ceiling('B') == 'C');

    cout << "bst size is : " << bst.size() << endl;
    // test select(1) = 'C'
    assert (bst.select(1) == 'C');
    // test select(10) = char(-1)   note: the size of the BST is 10, so there is not a Node with 10 nodes on its left
    cout << "test for select, this should be the char(0-1): " << bst.select(10) << endl;

    // test rank('a') = 0 none
    assert (bst.rank('0') == 0);
    // test rank('A') = 0 none
    assert (bst.rank('A') == 0);
    // test rank('C') = 1   A
    assert (bst.rank('C') == 1);
    // test rank('D') = 2   A C
    assert (bst.rank('D') == 2);
    // test rank('F') = 3   A C E
    assert (bst.rank('F') == 3);
    // test rank('X') = 9   
    assert (bst.rank('X') == 9);
    // test rank('Y') = 10  All
    assert (bst.rank('Y') == 10);

    // test deleteMin() -> A is deleted
    bst.preorder();
    bst.deleteMin();
    bst.preorder();

    // test deleteKey('A') -> A is deleted
    bst.preorder();
    bst.deleteKey('A');
    bst.preorder();

    // test deleteKey('D') -> no deleted
    bst.preorder();
    bst.deleteKey('D');
    bst.preorder();

    // test deleteMax() -> X is deleted
    bst.preorder();
    bst.deleteMax();
    bst.preorder();

    // I have not learn how to write Iterator for self-defined class, so no test for Keys()

    BST<int, int> bst_huge;
    double start = clock();
    for (int i = 0; i < 1E3; i++)
    {
        bst_huge.put(rand(), rand());
    }
    double end = clock();
    cout << (end - start) / CLOCKS_PER_SEC << endl;
    start = clock();
    for (int i = 0; i < 1E6; i++)
        bst_huge.get(rand());
    end = clock();
    cout << (end - start) / CLOCKS_PER_SEC << endl;
    
    cout << "-----------" << endl;
    cout << bst.check() << endl;
    
}