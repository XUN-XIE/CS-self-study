/* *****************************************************************************
 *  Name:              Alan Turing
 *  Coursera User ID:  123456
 *  Last modified:     1/1/2019
 **************************************************************************** */

package Chapter1.Chapter1_3.Exercise7;

import edu.princeton.cs.algs4.StdIn;
import edu.princeton.cs.algs4.StdOut;

import java.util.Iterator;

public class Stack<Item> implements Iterable<Item> {
    private Node first; // top of stack (most recently added node)
    private int N;      // number of items
    private Node peek;

    private class Node {  // nested class to define nodes
        Item item;
        Node next;
    }

    public boolean isEmpty() {
        return first == null;
    } // Or: N == 0.

    public int size() {
        return N;
    }

    public void push(Item item) { // Add item to top of stack.
        Node oldfirst = first;
        first = new Node();
        first.item = item;
        first.next = oldfirst;
        N++;

        peek.item = item;
        peek.next = oldfirst;
    }

    public Item pop() { // Remove item from top of stack.
        Item item = first.item;
        first = first.next;
        N--;
        
        peek = peek.next;

        return item;
    }

    public Iterator<Item> iterator() {
        return new ListIterator();
    }

    private class ListIterator implements Iterator<Item> {
        private Node current = first;

        public boolean hasNext() {
            return current != null;
        }

        public void remove() {
        }

        public Item next() {
            Item item = current.item;
            current = current.next;
            return item;
        }
    }

    public static void main(
            String[] args) { // Create a stack and push/pop strings as directed on StdIn.
        Stack<String> s = new Stack<String>();
        while (!StdIn.isEmpty()) {
            String item = StdIn.readString();
            if (!item.equals("-"))
                s.push(item);
            else if (!s.isEmpty()) StdOut.print(s.pop() + " ");
        }
        StdOut.println("(" + s.size() + " left on stack)");

        // How to create an array of Stack of which type is String !!!
        int N = 3;
        Stack<String>[] a = (Stack<String>[]) new Stack[N];
        for (int i = 0; i < N; i++) {
            a[i] = new Stack<String>();
            a[i].push("xie");
        }

        for (int i = 0; i < N; i++) {
            StdOut.println(a[i].pop());
        }
    }
}
