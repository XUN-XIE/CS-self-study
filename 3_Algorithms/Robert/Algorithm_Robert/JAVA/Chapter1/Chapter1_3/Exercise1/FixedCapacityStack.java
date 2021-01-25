/* *****************************************************************************
 *  Name:              Alan Turing
 *  Coursera User ID:  123456
 *  Last modified:     1/1/2019
 **************************************************************************** */

package Chapter1.Chapter1_3.Exercise1;

import edu.princeton.cs.algs4.StdIn;
import edu.princeton.cs.algs4.StdOut;

// learn how to apply generics
public class FixedCapacityStack<Item> {
    private Item[] a;   // stack entries
    private int N;      // size

    public FixedCapacityStack(int cap) {
        a = (Item[]) new Object[cap];
    }

    public boolean isFull() {
        return N >= a.length;
    }

    public boolean isEmpty() {
        return N == 0;
    }

    public int size() {
        return N;
    }

    public void push(Item item) {
        a[N++] = item;
    }

    public Item pop() {
        return a[--N];
    }

    public static void main(String[] args) {
        FixedCapacityStack<String> s;
        s = new FixedCapacityStack<String>(100);
        while (!StdIn.isEmpty()) {
            String item = StdIn.readString();
            if (!item.equals("-"))
                s.push(item);
            else if (!s.isEmpty()) StdOut.print(s.pop() + " ");
        }
        StdOut.println("(" + s.size() + " left on stack)");
    }
}
