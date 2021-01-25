/* *****************************************************************************
 *  Name:              Alan Turing
 *  Coursera User ID:  123456
 *  Last modified:     1/1/2019
 **************************************************************************** */

package Chapter3.Chapter3_1.Exercise24;

import edu.princeton.cs.algs4.Queue;
import edu.princeton.cs.algs4.StdOut;

public class BinarySearchST<Key extends Comparable<Key>, Value> {
    Key[] keys;
    Value[] vals;
    int N;

    public BinarySearchST(int capacity) { // See Algorithm 1.1 for standard array-resizing code.
        keys = (Key[]) new Comparable[capacity];
        vals = (Value[]) new Object[capacity];
    }

    public int size() {
        return N;
    }

    public boolean isEmpty() {
        return N == 0;
    }

    public Value get(Key key) {
        if (isEmpty()) return null;
        int i = rank(key);
        if (i < N && keys[i].compareTo(key) == 0) return vals[i];
        else return null;
    }

    public void put(Key key,
                    Value val) { // Search for key. Update value if found; grow table if new.
        int i = rank(key);
        if (i < N && keys[i].compareTo(key) == 0) {
            vals[i] = val;
            return;
        }
        for (int j = N; j > i; j--) {
            keys[j] = keys[j - 1];
            vals[j] = vals[j - 1];
        }
        keys[i] = key;
        vals[i] = val;
        N++;
    }

    public Key min() {
        return keys[0];
    }

    public Key max() {
        return keys[N - 1];
    }

    public Key select(int k) {
        return keys[k];
    }

    public Key ceiling(Key key) {
        int i = rank(key);
        return keys[i];
    }

    // Exercise 17 见答案，有更多情况的讨论和抛出异常
    public Key floor(Key key) {
        if (contains(key))
            return keys[rank(key)];
        else
            return keys[rank(key) - 1];
    }

    // Exercise 16 见答案，这样写是错误的，因为没有处理数组元素的前向移动！！！
    public void delete(Key key) {
        put(key, null);
    }

    public boolean contains(Key key) {
        return get(key) != null;
    }

    public Iterable<Key> keys(Key lo, Key hi) {
        Queue<Key> q = new Queue<Key>();
        for (int i = rank(lo); i < rank(hi); i++) q.enqueue(keys[i]);
        if (contains(hi))
            q.enqueue(keys[rank(hi)]);
        return q;
    }

    public int rank(Key key) {
        int lo = 0, hi = N - 1;
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            int cmp = key.compareTo(keys[mid]);
            if (cmp < 0) hi = mid - 1;
            else if (cmp > 0) lo = mid + 1;
            else return mid;
        }
        return lo;
    }


    public static void main(String[] args) {
        BinarySearchST<Integer, Integer> test = new BinarySearchST<Integer, Integer>(10);
        test.put(1, 2);
        test.put(2, 3);
        test.put(3, 4);
        test.put(10, 5);
        StdOut.println(test.rank(10));


        Comparable<Integer>[] key = (Integer[]) new Comparable[1];
        int lo = 0, hi = test.size() - 1;
        int found_index;
        while (lo <= hi) {
            int mid = (key[0] - lo) / (hi - lo);
            int cmp = key[0] > test.keys[mid] ? 1 : -1;
            if (key[0] == test.keys[mid])
                cmp = 0;
            if (cmp < 0) hi = mid - 1;
            else if (cmp > 0) lo = mid + 1;
            else found_index = mid;
        }
        found_index = lo;
        StdOut.println(found_index);
    }
}

