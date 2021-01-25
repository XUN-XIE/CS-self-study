/* *****************************************************************************
 *  Name:              Alan Turing
 *  Coursera User ID:  123456
 *  Last modified:     1/1/2019
 **************************************************************************** */

package Chapter3.Chapter3_1.知识点;

import edu.princeton.cs.algs4.Queue;

public class SequentialSearchST<Key, Value> {
    private Node first;  // first node in the linked list

    private class Node { // linked-list node
        Key key;
        Value val;
        Node next;

        public Node(Key key, Value val, Node next) {
            this.key = key;
            this.val = val;
            this.next = next;
        }
    }

    public Value get(Key key) { // Search for key, return associated value.
        for (Node x = first; x != null; x = x.next)
            if (key.equals(x.key)) // search hit
                return x.val;
        return null;                // search miss
    }

    public void put(Key key,
                    Value val) { // Search for key. Update value if found; grow table if new.
        for (Node x = first; x != null; x = x.next)
            if (key.equals(x.key)) {
                x.val = val;
                return;
            } // Search hit: update val.
        first = new Node(key, val, first); // Search miss: add new node.
    }

    // Exercise 5
    public int size() {
        int count = 0;
        for (Node x = first; x != null; x = x.next)
            count++;
        return count;
    }

    // Exercise 5
    public void delete(Key key) {
        put(key, null);
    }

    // Exercise 5
    public Iterable<Key> keys() {
        Queue<Key> q = new Queue<Key>();
        for (Node x = first; x != null; x = x.next)
            q.enqueue(x.key);
        
        return q;
    }
}
