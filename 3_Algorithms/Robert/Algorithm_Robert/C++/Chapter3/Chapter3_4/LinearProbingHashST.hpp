#include <bits/stdc++.h>
using namespace std;

template <typename Key, typename Value>
class LinearProbingHashST
{
private:
    int N;
    int M = 16;
    vector<Key> keys;
    vector<Value> vals;

    int hashKey(Key key)   
    {   
        int tmp = (hash<Key>()(key) & 0x7fffffff);
        return tmp % M;
    }

    void resize(int size)
    {
        LinearProbingHashST<Key, Value> t(size);
        for (int i = 0; i < M; i++)
            if (keys[i] != -1)
                t.put(keys[i], vals[i]);
        keys = t.keys;
        vals = t.vals;
        M = t.M;
    }
public:
    // 这里keys数组的默认改为-1，表示为空！！！
    LinearProbingHashST()   {   keys = vector<Key>(M, -1);  vals = vector<Value>(M);    }
    LinearProbingHashST(int m)  {   M = m; keys = vector<Key>(M, -1);  vals = vector<Value>(M); }

    void put(Key key, Value val)
    {
        if (N >= M / 2) resize(2 * M);

        int i;
        for (i = hashKey(key); keys[i] != -1; i = (i + 1) % M)
            if (keys[i] == key)
            {
                vals[i] = val;
                return;
            }
        keys[i] = key;
        vals[i] = val;
        N++;
    }

    Value get(Key key)
    {
        // 这个判断条件需要改一下，C++和JAVA默认对类型的构造不一样！
        // 所以改了keys数组的默认构造为 -1，表示空
        for (int i = hashKey(key); keys[i] != -1; i = (i + 1) % M)
            if (keys[i] == key)
                return vals[i];
        return -1;
    }

    void deleteKey(Key key)
    {
        if (!contains(key)) return;
        int i = hashKey(key);
        while (key != keys[i])
            i = (i + 1) % M;
        // -1 表示空值
        keys[i] = -1;
        vals[i] = -1;
        i = (i + 1) % M;

        // 直到遇到下一个空值前，把所有的有值的点重新放置！！！
        while (keys[i] != -1)
        {
            Key keyToRedo = keys[i];
            Value valToRedo = vals[i];
            keys[i] = -1;
            vals[i] = -1;
            N--;
            put(keyToRedo, valToRedo);
            i = (i + 1) % M;
        }
        N--;
        if (N > 0 && N <= M / 8)    resize(M / 2);
    }

    bool contains(Key key)  {   return get(key) != -1;  }
};