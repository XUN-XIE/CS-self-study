#ifndef BINARYSEARCHTREE_HPP
#define BINARYSEARCHTREE_HPP
#include <bits/stdc++.h>
using namespace std;

// 因为使用了template，一些Node == NULL时返回值需要成为通用的返回值，因此NULL不适合返回
// 所以采用了返回 -1， 为返回值，需要特别注意输出 -1和 其他类型对应 -1的转换

// Node class constructor有个大陷阱，阅读！！！
template <typename Key, typename Value>
class Node
{
public:
    Key key;
    Value val;
    Node *left, *right;
    int N;
    Node()  {   left = NULL; right = NULL; N = 0; }
    // !!!!!!!!!!!!!!!!!!!!!!!! 这个 constructor 有个陷阱，切记要给left和right设置为 NULL
    // 否则！！！ left 和 right 是野指针！！！ 在后续的 Node == NULL 判断中会失效！！！导致从野指针取值！！！
    Node(Key k, Value v, int n) {   key = k; val = v; N = n; left = right = NULL;   }
    ~Node() {   delete left; delete right;  }
};


template <typename Key, typename Value>
class BST
{
private:
    Node<Key, Value> *root;
    int size(Node<Key, Value> * x)
    {
        if (x == NULL)  
            return 0;
        else            
            return x->N;
    }

// recursive version for get method
/*
    // Return value associated with key in the subtree rooted at x;
    // return null if key not present in subtree rooted at x.
    // Value get(Node<Key, Value> * x, Key key)
    // {
    //     // 这里返回 0 还不能理解。JAVA是返回null，但是C++不可以，类型不匹配
    //     if (x == NULL)  return -1;
    //     int cmp = key > x->key ? 1 : -1;
    //     if (key == x->key)   cmp = 0;
        
    //     if (cmp < 0)        return get(x->left, key);
    //     else if (cmp > 0)   return get(x->right, key);
    //     else                return x->val;
    // }
*/

    // Exercise 13
    // nonrecursive get method
    // get method 不需要更新 Node 的 size
    Value get(Node<Key, Value> * x, Key key)
    {
        while ( x != NULL )
        {
            int cmp = key > x->key ? 1 : -1;
            if (key == x->key)   cmp = 0;

            if (cmp < 0)
                x = x->left;
            else if (cmp > 0)
                x = x->right;
            else
                break;
        }
        if (x == NULL)
            return -1;
        return x->val;
    }

    // Change key’s value to val if key in subtree rooted at x.
    // Otherwise, add new node to subtree associating key with val.
    Node<Key, Value> * put(Node<Key, Value> * x, Key key, Value val)
    {
        if (x == NULL)  return new Node<Key, Value>(key, val, 1);
        int cmp = key > x->key ? 1 : -1;
        if (key == x->key)   cmp = 0;

        if (cmp < 0)        x->left = put(x->left, key, val);
        else if (cmp > 0)   x->right = put(x->right, key, val);
        else x->val = val;
        x->N = size(x->left) + size(x->right) + 1;
        return x;
    }

    // recursive version
    Node<Key, Value> * min(Node<Key, Value> * x)
    {
        if (x->left == NULL) return x;
        return min(x->left);
    }

    // recursive version for floor method
    Node<Key, Value> * floor(Node<Key, Value> * x, Key key)
    {
        if (x == NULL)  return NULL;
        int cmp = key > x->key ? 1 : -1;
        if (key == x->key)   cmp = 0;

        if (cmp == 0)   return x;
        // 先找到第一个floor，再进入下一步t，开始寻找有没有更接近floor的存在
        if (cmp < 0)    return floor(x->left, key);
        // 这时，每次向右走一步，都等于把floor更新了一次为 x ！
        Node<Key, Value> * t = floor(x->right,key);
        if (t != NULL)  return t;
        // 这是为了处理 最后一个Node时，它的孩子肯定为NULL，所以往回倒一次
        // 因为返回的是NULL，所以这时return的x就是等于Node的
        else            return x;
    }

    // recursive version
    Node<Key, Value> * max(Node<Key, Value> * x)
    {
        if (x->right == NULL) return x;
        return max(x->right);
    }

    // recursive version
    Node<Key, Value> * ceiling(Node<Key, Value> * x, Key key)
    {
        if (x == NULL)  return NULL;
        int cmp = key > x->key ? 1 : -1;
        if (key == x->key)   cmp = 0;

        if (cmp == 0)   return x;
        if (cmp > 0)    return ceiling(x->right, key);
        Node<Key, Value> * t = ceiling(x->left, key);
        if (t != NULL)  return t;
        else            return x;
    }

    // recursive version
    // Return Node containing key of rank k.
    Node<Key, Value> * select(Node<Key, Value> * x, int k)
    {
        if (x == NULL)  return NULL;
        int t = size(x->left);
        
        if      (t > k) return select(x->left, k);
        else if (t < k) return select(x->right, k-t-1);
        else            return x;
    }

    // recursive version
    // Return number of keys less than x.key in the subtree rooted at x.
    // Note: if the given key is less than minimmum of the keys in tree, it also return 0
    // which is same as you input the smallest key
    int rank(Key key, Node<Key, Value> * x)
    {
        if (x == NULL)  return 0;
        int cmp = key > x->key ? 1 : -1;
        if (key == x->key)   cmp = 0;

        if (cmp < 0)        return rank(key, x->left);
        else if (cmp > 0)   return 1 + size(x->left) + rank(key, x->right);
        else                return size(x->left);
    }

    Node<Key, Value> * deleteMin(Node<Key, Value> * x)
    {
        // 找到最小值Node的右结点
        if (x->left == NULL) return x->right;
        // 更新最小节点父亲的左节点为最小值的右结点
        x->left = deleteMin(x->left);
        // 回溯更新size N
        x->N = size(x->left) + size(x->right) + 1;
        return x;
    }

    Node<Key, Value> * deleteMax(Node<Key, Value> * x)
    {
        // 找到最小值Node的右结点
        if (x->right == NULL) return x->left;
        // 更新最小节点父亲的左节点为最小值的右结点
        x->right = deleteMin(x->right);
        // 回溯更新size N
        x->N = size(x->left) + size(x->right) + 1;
        return x;
    }

    Node<Key, Value> * deleteKey(Node<Key, Value> * x, Key key)
    {
        if (x == NULL)  return NULL;
        int cmp = key > x->key ? 1 : -1;
        if (key == x->key)   cmp = 0;

        if (cmp < 0)    x->left = deleteKey(x->left, key);
        else if (cmp > 0)   x->right = deleteKey(x->right, key);
        else
        {
            if (x->right == NULL)    return x->left;
            if (x->left == NULL)     return x->right;
            Node<Key, Value> * t = x;
            // 寻找 待删除 Node 的后继
            x = min(t->right);
            x->right = deleteMin(t->right);
            x->left = t->left;
        }
        x->N = size(x->left) + size(x->right) + 1;
        return x;
    }

    // 先序遍历
    void preorder(Node<Key, Value> * x)
    {
        if (x == NULL) return;
        cout << x->key << " ";
        preorder(x->left);
        preorder(x->right);
    }
    // 中序遍历
    void inorder(Node<Key, Value> * x)
    {
        if (x == NULL) return;
        preorder(x->left);
        cout << x->key << " ";
        preorder(x->right);
    }
    // 后序遍历
    void postorder(Node<Key, Value> * x)
    {
        if (x == NULL) return;
        preorder(x->left);
        preorder(x->right);
        cout << x->key << " ";
    }
    // 层序遍历
    void levelOrder(Node<Key, Value> * x)
    {
        queue<Node<Key, Value > * > que;
        if (x == NULL)
            return;
        que.push(x);
        while (!que.empty())
        {
            Node<Key, Value > * t = que.front();
            cout << t->key << " ";
            if (t->left != NULL)
                que.push(t->left);
            if (t->right != NULL)
                que.push(t->right);
            que.pop();
        }
    }
    // Exercise 6
    void height(Node<Key, Value> * x, Key key, int & count)
    {
        count++;
        if (x == NULL)  {count = -1; return;}
        int cmp = key > x->key ? 1 : -1;
        if (key == x->key)   cmp = 0;

        if(cmp < 0)     height(x->left, key, count);
        else if (cmp > 0)    height(x->right, key, count);
        else return;
    }

    // Exercise 29 -> 32 见答案
    // does this binary tree satisfy symmetric order?
    // Note: this test also ensures that data structure is a binary tree since order is strict
    bool isBST()    {   return isBST(root, min(), max()); }
    // is the tree rooted at x a BST with all keys strictly between min and max
    // (if min or max is null, treat as empty constraint)
    bool isBST(Node<Key, Value> * x, Key min, Key max)
    {
        if (x == NULL)  return true;
        if (x->key < min)   return false;
        if (x->key > max)   return false;
        return isBST(x->left, min, x->key) && isBST(x->right, x->key, max);
    }

    // are the size fields correct?
    bool isSizeConsistent() {   return isSizeConsistent(root);  }
    bool isSizeConsistent(Node<Key, Value> * x)
    {
        if (x == NULL)  return true;
        if (x->N != size(x->left) + size(x->right) + 1)  return false;
        return isSizeConsistent(x->left) && isSizeConsistent(x->right);
    }

    // check that ranks are consistent
    bool isRankConsistent()
    {
        for (int i = 0; i < size(); i++)
            if (i != rank(select(i)))   return false;
        // // 另一部分需要写Iterator，用自己写的isSRankConsistent代替判断
        // for (Key key : keys())
        //     if (key != select(rank(key)))   return false;
        bool consistent = true;
        isSRankConsistent(root, consistent);
        return consistent;
    }

    // 虽然还不会写 Iterator，但是可以借助 先序遍历的思想遍历判断
    void isSRankConsistent(Node<Key, Value> * x, bool & consistent)
    {
        if (x == NULL)  return;
        if (x->key != select(rank(x->key)))  {   consistent = false; return; }
        isSRankConsistent(x->left, consistent);
        isSRankConsistent(x->right, consistent);
    }
public:
    BST()   {   root = NULL;    }
    ~BST()  {   delete root;    }
    int size() {    return size(root);  }
    Value get(Key key)  {   return get(root, key);  }

    // Search for key. Update value if found; grow table if new.
    void put(Key key, Value val) {  root = put(root, key, val);  }

// Exercise 13 nonrecursive put method
/*
    // // 但是这个版本的 put method 要求的是 Node 自身不包含自己的size，也就是有多少子树Node
    // void put(Key key, Value val)
    // {
    //     Node<Key, Value> * z = new Node<Key, Value>(key, val, 1);
    //     if (root == NULL)
    //     {
    //         root = z;
    //         return;
    //     }
    //     Node<Key, Value> * parent = NULL, * x = root;
    //     while (x != NULL)  
    //     {
    //         parent = x;
    //         int cmp = key > x->key ? 1 : -1;
    //         if (key == x->key)   cmp = 0;
    //         if (cmp < 0)
    //             x = x->left;
    //         else if (cmp > 0)
    //             x = x->right;
    //         else 
    //         {
    //             x->val = val;
    //             return;
    //         }
    //     }
    //     int cmp = key > parent->key ? 1 : -1;
    //     if (key == parent->key)   cmp = 0;
    //     if (cmp < 0)    parent->left = z;
    //     else            parent->right = z;
    // }
*/

    // Key min()   {   return min(root)->key;   };

    // Exercise 14
    // Nonrecursive min
    Key min()
    {
        if (root == NULL)
            return -1;
        Node<Key, Value> * x = root;
        while (x->left != NULL) x = x->left;
        return x->key;
    }

    // Key floor(Key key)
    // {
    //     Node<Key, Value> * x = floor(root, key);
    //     if (x == NULL)  return -1;
    //     return x->key;
    // }

    // Exercise 14
    // Nonrecursive floor 
    Key floor(Key key)
    {
        Node<Key, Value> * x = root;
        Node<Key, Value> * t = NULL;
        while (x != NULL)
        {
            int cmp = key > x->key ? 1 : -1;
            if (key == x->key)   cmp = 0;

            if (cmp == 0)   return x->key;
            else if (cmp < 0)
            {
                x = x->left;
                continue;
            }
            else
            {
                t = x;
                x = x->right;
            }
        }
        if (t != NULL)  return t->key;
        else if (x == NULL) return -1;
        else            return x->key;
    }

    // Key max()   {   return max(root)->key;   }
    // Exercise 14
    // Nonrecursive max
    Key max()
    {
        if (root == NULL)
            return -1;
        Node<Key, Value> * x = root;
        while (x->right != NULL) x = x->right;
        return x->key;
    }

    // Key ceiling(Key key)
    // {
    //     Node<Key, Value> * x = ceiling(root, key);
    //     if (x == NULL)  return -1;
    //     return x->key;
    // }

    // Exercise 14
    // Nonrecursive ceiling
    Key ceiling(Key key)
    {
        Node<Key, Value> * x = root;
        Node<Key, Value> * t = NULL;
        while (x != NULL)
        {
            int cmp = key > x->key ? 1 : -1;
            if (key == x->key)   cmp = 0;

            if (cmp == 0)   return x->key;
            else if (cmp > 0)
            {
                x = x->right;
                continue;
            }
            else
            {
                t = x;
                x = x->left;
            }
        }
        if (t != NULL)  return t->key;
        else if (x == NULL) return -1;
        else            return x->key;
    }

    // Key select(int k)
    // {
    //     if ( k < 0 || k >= size(root))
    //         return -1;
    //     return select(root, k)->key;
    // }

    // Exercise 14
    // Nonrecursive select
    Key select(int k)
    {
        if ( k < 0 || k >= size(root))
            return -1;
        Node<Key, Value> * x = root;
        while (x != NULL)
        {
            int t = size(x->left);

            if (t > k)
                x = x->left;
            else if (t < k)
            {
                x = x->right;
                k = k - t - 1;
            }
            else
                return x->key;
        }
        return -1;
    }
    
    // int rank(Key key)   {   return rank(key, root);     }

    // Exercise 14
    // Nonrecursive rank
    int rank(Key key)
    {
        Node<Key, Value> * x = root;
        int count = 0;
        while (x != NULL)
        {
            int cmp = key > x->key ? 1 : -1;
            if (key == x->key)   cmp = 0;

            if (cmp < 0)
                x = x->left;
            else if (cmp > 0)
            {
                count += 1 + size(x->left);
                x = x->right;
            }
            else
            {
                count += size(x->left);
                return count;
            }
        }
        return count;
    }

    void deleteMin() {  root = deleteMin(root); }
    void deleteMax() {  root = deleteMax(root); }
    void deleteKey(Key key) {   root = deleteKey(root, key);    }

    void preorder()     {   preorder(root); cout << endl;   }
    void inorder()      {   inorder(root);  cout << endl;   }
    void postorder()    {   postorder(root);cout << endl;   }
    void levelOrder()   {   levelOrder(root); cout << endl; }

    int height(Key key)
    {
        int count = 0;
        height(root, key, count);
        return count;
    }

    bool check()
    {
        if (!isBST())           cout << "Not in symmetric order" << endl;
        if (!isSizeConsistent())cout << "Subtree counts not consistent" << endl;
        if (!isRankConsistent())cout << "Ranks not consistent" << endl;
        return isBST() && isSizeConsistent() && isRankConsistent();
    }
};
#endif