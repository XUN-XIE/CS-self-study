#include <bits/stdc++.h>
using namespace std;

template <typename Key, typename Value>
class Node
{
public:
    Key key;
    Value val;
    Node<Key, Value> * next;
    Node()  {   next = NULL;    }
    Node(Key k, Value v, Node<Key, Value> * n) : key(k), val(v), next(n)   {}
    ~Node()    {   delete next;    }
};

template <typename Key, typename Value>
class SequentialSearchST
{
private:
    Node<Key, Value> * first;
public:
    SequentialSearchST()    {   first = NULL;   }
    ~SequentialSearchST()   {   delete first;   }
    Value get(Key key)
    {
        if (first == NULL)
            return -1;
        Node<Key, Value> * tmp = first;
        while (tmp != NULL)
        {
            if (tmp->key == key)
                return tmp->val;
            else
                tmp = tmp->next;
        }
        return -1;
    }

    void put(Key key, Value val)
    {
        if (first == NULL)  {   first = new Node<Key, Value>(key, val, NULL);  return;  }
        Node<Key, Value> * tmp = first;
        while (tmp != NULL)
        {
            if (tmp->key == key) {   tmp->val = val;    return; }
            else                    tmp = tmp->next;
        }
        first = new Node<Key, Value>(key, val, first);
    }

    void deleteKey(Key key)
    {
        if (first == NULL)  return;

        Node<Key, Value > * prev = NULL;
        Node<Key, Value > * cur = first;

        //  找到对应 Node
        while (cur->key != key)
        {
            prev = cur;
            cur = cur->next;
        }
        
        if (cur == first)
        {
            if (cur->next == NULL)
                first = NULL;
            else if (cur->next != NULL)
            {
                first = cur->next;
                cur->next = NULL;
            }
            return ;
        }

        if (cur->next == NULL)
            prev->next = NULL;
        else
        {
            prev->next = cur->next;
            cur->next = NULL;
        }
    }
};