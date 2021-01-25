/* *****************************************************************************
 *  Name:              Alan Turing
 *  Coursera User ID:  123456
 *  Last modified:     1/1/2019
 **************************************************************************** */

package Chapter1.Chapter1_3.Exercise14;

import java.util.Iterator;

// my own version by changing some code from ResizingArrayStack
public class ResizingArrayQueueOfStrings<Item> implements Iterable<Item> {
    private Item[] a = (Item[]) new Object[1];  // stack items
    private int N = 0;                          // number of items

    public boolean isEmpty() {
        return N == 0;
    }

    public int size() {
        return N;
    }

    private void resize(int max) { // Move stack to a new array of size max.
        Item[] temp = (Item[]) new Object[max];
        for (int i = 0; i < N; i++)
            temp[i] = a[i];
        a = temp;
    }

    public void enqueue(Item item) { // Add item to top of stack.
        if (N == a.length) resize(2 * a.length);
        a[N++] = item;
    }

    public Item deque() { // Remove item from top of stack.
        Item item = a[0];
        for (int i = 0; i < N - 1; i++)
            a[i] = a[i + 1];
        a[--N] = null; // Avoid loitering (see text).
        if (N > 0 && N == a.length / 4) resize(a.length / 2);
        return item;
    }


    // Important
    public Iterator<Item> iterator() {
        return new ReverseArrayIterator();
    }

    private class ReverseArrayIterator implements Iterator<Item> { // Support LIFO iteration.
        private int i = N;

        public boolean hasNext() {
            return i > 0;
        }

        public Item next() {
            return a[--i];
        }

        public void remove() {
        }
    }
}
