#include <bits/stdc++.h>
using namespace std;

// 今后所有的类似数据结构中如果使用 class Node，都会把Node的成员设置为public，为了一些应用

// 自己写 Stack 不管是 array 还是 linkedlist 实现都感觉自己对C++的理解不到位
// 比如 在Stack的析构函数中，我有必要遍历所有的Node，把所有的Node都delete了吗？
// 根据 Allen Weiss 对linkedlist的实现，析构函数不需要遍历delete！
template <typename Item>
class Node
{
public:
    Item item;
    Node<Item> * next;
    Node() : next(NULL) {}
    Node(Item i) : item(i), next(NULL) {}
    ~Node() {   delete next;    }
};

template <typename Item>
class Stack
{
private:
    Node<Item> * first;
    int N;

public:
    Stack() : first(NULL) {}
    ~Stack()    {   delete first;   }
    bool isEmpty()  {   return first == NULL;   }
    int size()      {   return N;   }

    // 因为 LinkedList 是首部插入，所以可以不用判断first是否为空
    void push(Item item)
    {
        Node<Item> * oldfirst = first;
        first = new Node<Item>(item);
        first->next = oldfirst;
        N++;
    }

    Item pop()
    {
        if (first == NULL)  return -1;
        Item item = first->item;
        first = first->next;
        N--;
        return item;
    }

    void print()
    {
        if (first == NULL)  return;
        Node<Item> * cur = first;
        while (cur != NULL)
        {
            cout << cur->item << " ";
            cur = cur->next;
        }
        cout << endl;
    }
};