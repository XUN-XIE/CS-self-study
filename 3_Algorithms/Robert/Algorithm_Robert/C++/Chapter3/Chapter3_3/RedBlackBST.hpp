#ifndef REDBLACKBST_HPP
#define REDBLACKBST_HPP
#include <bits/stdc++.h>
using namespace std;

#define RED true
#define BLACK false

// 红黑树和普通的平衡二叉树，代码区别仅在于 put， delete两个相关的method
// 因此其他的代码可以直接从 BST 中粘贴过来


// 又经过对比网上的答案在JAVA中测试 以及我自己又重新测试C++代码
// 发现！！！ deleteMin, deleteMax是不能一直调用的！！！
// C++会出现空指针调用对象
// JAVA 中会出现 root 为空的情况！！！
// 这说明 deleteMin 方法其实并没有很好的回溯调整好整个红黑树，起码从目前我见到的JAVA和C++代码中是这样的！

// 照着写 delete 方法，要求很严格，需要key必须存在，其实可以实现一个 contain 方法
template <typename Key, typename Value>
class Node
{
public:
    Key key;
    Value val;
    Node<Key, Value> * left, * right;
    int N;
    bool color;
    Node()  {   left = right = NULL;    N = 0;  color = BLACK;  }
    Node(Key k, Value v, int n, bool c) { left = right = NULL; key = k; val = v; N = n; color = c;  }
    ~Node() {   delete left; delete right;  }
};

template <typename Key, typename Value>
class RedBlackBST
{
private:
    Node<Key, Value> * root;
    // most important four methods
    // isRed, roateRight, rotateLeft, flipColors
    bool isRed(Node<Key, Value> * x)
    {
        if (x == NULL)  return false;
        return x->color == RED;
    }

    Node<Key, Value> * rotateRight(Node<Key, Value> * h)
    {
        Node<Key, Value> * x = h->left;
        h->left = x->right;
        x->right = h;
        x->color = h->color;
        h->color = RED;
        x->N = h->N;
        h->N = 1 + size(h->left) + size(h->right);
        return x;
    }

    Node<Key, Value> * rotateLeft(Node<Key, Value> * h)
    {
        Node<Key, Value> * x = h->right;
        h->right = x->left;
        x->left = h;
        x->color = h->color;
        h->color = RED;
        x->N = h->N;
        h->N = 1 + size(h->left) + size(h->right);
        return x;
    }

    void flipColors(Node<Key, Value> * h)
    {
        h->color = RED;
        h->left->color = BLACK;
        h->right->color = BLACK;
    }

    // left code is just like the BST implementation, but not the same
    int size(Node<Key, Value> * h)
    {
        if (h == NULL)  return 0;
        return h->N;
    }

    Node<Key, Value> * put(Node<Key, Value> * h, Key key, Value val)
    {
        // 注意这里插入新的Node，都是令其为红色的！
        // 思考：因为先随意在原来的2-3Node上添加
        // 如果超出了，自然会向上进行调整，所以为了保证向上调整，自然使用红点插入
        // Do standard insert, with red link to parent.
        if (h == NULL)  return new Node<Key, Value>(key, val, 1, RED);

        int cmp = key < h->key ? -1 : 1;
        if (key == h->key)  cmp = 0;

        if (cmp < 0)        h->left = put(h->left, key, val);
        else if (cmp > 0)   h->right = put(h->right, key, val);
        else                h->val = val;

////////// most important part !!!
        // 仔细思考，发现书中提到的六种插入情况，其实用这 固定顺序！ 的三步就可以完全解决了
        // 因为先判断了最复杂的情况，就是左红点后的点右红点，然后继续步步走，因此六种情况都包含了

        // 第一步调整 right leaning to left leaning
        if (isRed(h->right) && !isRed(h->left))         h = rotateLeft(h);
        // 第二步调整 左连环红点情况
        if (isRed(h->left)  &&  isRed(h->left->left))   h = rotateRight(h);
        // 第三部调整 four Nodes 情况
        if (isRed(h->left)  &&  isRed(h->right))        flipColors(h);

        h->N = size(h->left) + size(h->right) + 1;
        return h;
    }

    // flipColors 前不明白为什么不check一下yoright是不是存在？？？？ 导致出现了调用空指针的情况
    Node<Key, Value> * moveRedLeft(Node<Key, Value> * h)
    {
        // Assuming that h is red and both h.left and h.left.left
        // are black, make h.left or one of its children red.
        flipColors(h);
        if (isRed(h->right->left))
        {
            h->right = rotateRight(h->right);
            h = rotateLeft(h);
        }
        return h;
    }

    Node<Key, Value> * balance(Node<Key, Value> * h)  
    {   
        if (isRed(h->right))                            h = rotateLeft(h);
        if (isRed(h->left)  &&  isRed(h->left->left))   h = rotateRight(h);
        if (isRed(h->left)  &&  isRed(h->right))        flipColors(h);
        h->N = size(h->left) + size(h->right) + 1;
        return h;
    }

    Node<Key, Value> * deleteMin(Node<Key, Value> * h)
    {
        if (h->left == NULL)
            return NULL;

        if (!isRed(h->left) && !isRed(h->left->left))
            h = moveRedLeft(h);
            
        h->left = deleteMin(h->left);
        return balance(h);
    }

    Node<Key, Value> * moveRedRight(Node<Key, Value> * h)
    {
        flipColors(h);
        if (!isRed(h->left->left))
            h = rotateRight(h);
        return h;
    }

    Node<Key, Value> * deleteMax(Node<Key, Value> * h)
    {   
        if (isRed(h->left))
            h = rotateRight(h);

        if (h->right == NULL)
            return NULL;

        if (!isRed(h->right) && !isRed(h->right->left))
            h = moveRedLeft(h);
            
        h->right = deleteMax(h->right);
        return balance(h);
    }

    Node<Key, Value> * deleteKey(Node<Key, Value> * h, Key key)
    {
        if (key < h->key)
        {
            if (!isRed(h->left) && !isRed(root->left->left))
                h = moveRedLeft(h);
            h->left = deleteKey(h->left, key);
        }
        else
        {
            if (isRed(h->left))
                h = rotateRight(h);
            if (key == h->key && h->right == NULL)
                return NULL;
            if (!isRed(h->right) && !isRed(h->right->left))
                h = moveRedRight(h);
            if (key == h->key)
            {
                h->val = get(h->right, min(h->right)->key);
                h->key = min(h->right)->key;
                h->right = deleteMin(h->right);
            }
            else
                h->right = deleteKey(h->right, key);
        }
        return balance(h);
    }

    bool isEmpty()  {   return root == NULL;    }

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
                return x->val;
        }

        return -1;
        
    }

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

    void levelOrder(Node<Key, Value> * x)
    {
        queue<Node<Key, Value > * > que;
        if (x == NULL)
            return;
        que.push(x);
        while (!que.empty())
        {
            Node<Key, Value > * t = que.front();
            cout << t->key << " " << t->color << endl;
            if (t->left != NULL)
                que.push(t->left);
            if (t->right != NULL)
                que.push(t->right);
            que.pop();
        }
    }
public:
    RedBlackBST()   {   root = NULL;    }
    ~RedBlackBST()  {   delete root;    }
    int size()  {   return size(root); }

    // Search for key. Update value if found; grow table if new.
    void put(Key key, Value val)
    {
        root = put(root, key, val);
        root->color = BLACK;
    }

    void deleteMin()
    {
        if (!isRed(root->left) && !isRed(root->right))
            root->color = RED;
        root = deleteMin(root);
        if (!isEmpty()) root->color = BLACK;
    }

    void deleteMax()
    {
        if (!isRed(root->left) && !isRed(root->right))
            root->color = RED;
        root = deleteMax(root);
        if (!isEmpty()) root->color = BLACK;
    }

    void deleteKey(Key key)
    {
        if (!isRed(root->left) && !isRed(root->right))
            root->color = RED;
        root = deleteKey(root, key);
        if (!isEmpty()) root->color = BLACK;
    }

    Value get(Key key)  {   return get(root, key);  }
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

    void preorder()     {   preorder(root); cout << endl;   }
    void inorder()      {   inorder(root);  cout << endl;   }
    void postorder()    {   postorder(root);cout << endl;   }
    void levelOrder()   {   levelOrder(root); cout << endl; }
};

#endif