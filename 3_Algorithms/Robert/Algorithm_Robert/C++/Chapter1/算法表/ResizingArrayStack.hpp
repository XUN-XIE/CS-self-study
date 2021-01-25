#include <bits/stdc++.h>
using namespace std;

// 自己的C++内置数组用的还是不够好，所以写 resize 函数的时候导致一个指针的bug
template <typename Item>
class ResizingArrayStack
{
private:
    Item * a;
    int N;
    int capacity;
    void resize(int max)
    {
        Item * tmp = new Item[max];
        for (int i = 0;i < N; i++)
            tmp[i] = a[i];
        
        // 这一步很关键，不能用 a = tmp, 不然原来 a 数组的值没有被删除
        // 用swap确保了交换。
        swap(a, tmp);
        delete [] tmp;
        capacity = max;
    }
public:
    ResizingArrayStack()    {   a = new Item[1]; N = 0; capacity = 1;   }
    ResizingArrayStack(int cap)    {   a = new Item[cap]; N = 0; capacity = cap; }
    ~ResizingArrayStack()   {   delete [] a;   }
    bool isEmpty()  {   return N == 0;  }
    int size()      {   return N;   }
    void push(Item item)
    {
        if (N == capacity)  resize(2 * capacity);
        a[N++] = item;
    }

    Item pop()
    {
        Item item = a[--N];
        a[N] = -1;
        if (N > 0 && N == capacity / 4) resize(capacity / 2);
        return item;
    }

    void print()
    {
        for (int i = 0; i < N; i++)
            cout << a[i] << " ";
        cout << endl;
    }
};