#include "SequentialSearchST.hpp"

template <typename Key, typename Value>
class SeparateChainingHash
{
private:
    int N;
    int M;
    vector<SequentialSearchST<Key, Value > > st;

    // 相当于限制所有输入的数据，必须在 int 32位表示的最大值范围内！防止超出int的范围
    // 0x7fffffff = RAND_MAX = pow(2, 31)
    // hash<Key>()(key), 理解，hash是一个class，第一个圆括号且之前是用来创建一个表示key类型的对象，然后第二个括号是传入参数调用对象的方法，得到hash value
    int hashKey(Key key)   
    {   
        int tmp = (hash<Key>()(key) & 0x7fffffff);
        return tmp % M;
    }

public:
    // C++ 不要用默认构造函数调用另一个构造函数，会出现内部机制的问题，所以第一个bug由此产生
    SeparateChainingHash()  {   M = 997; st = vector<SequentialSearchST<Key, Value > >(M);    }
    SeparateChainingHash(int m) {   M = m;  st = vector<SequentialSearchST<Key, Value > >(M); }

    Value get(Key key)  {   return st[hashKey(key)].get(key);   }

    void put(Key key, Value val)    {   st[hashKey(key)].put(key, val); }

    // Exercise 9
    void deleteKey(Key key) {   st[hashKey(key)].deleteKey(key);    }

    bool contains(Key key)  {   return get(key) != -1;  }
};
