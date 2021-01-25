/* *****************************************************************************
 *  Name:              Alan Turing
 *  Coursera User ID:  123456
 *  Last modified:     1/1/2019
 **************************************************************************** */

package Chapter1.Chapter1_3.Exercise_linked_list;

import edu.princeton.cs.algs4.StdIn;
import edu.princeton.cs.algs4.StdOut;

import java.util.Iterator;

public class CircularQueue<Item> {
    private Node last;  // link to most recently added node
    private int N;

    private class Node {  // nested class to define nodes
        Item item;
        Node next;
    }

    public boolean isEmpty() {
        return last == null;
    }

    public int size() {
        return N;
    }

    public void enqueue(Item item) { // Add item to the end of the list.
        if (isEmpty()) {
            last = new Node();
            last.item = item;
            last.next = last;
            N++;
            return;
        }

        if (size() == 1) {
            Node tmp = new Node();
            tmp.item = item;
            last.next = tmp;
            tmp.next = last;
            N++;
        }
        else {
            Node oldlast = last;
            last = new Node();
            last.item = item;
            last.next = oldlast.next;
            oldlast.next = last;
            N++;
        }
    }

    public Item dequeue() { // Remove item from the beginning of the list.
        if (isEmpty()) return null;
        if (size() == 1) {
            Item item = last.item;
            last = null;
            N--;
            return item;
        }
        else {
            Item item = last.next.item;
            last.next = last.next.next;
            N--;
            return item;
        }
    }

    public Iterator<Item> iterator() {
        return new ListIterator();
    }

    private class ListIterator implements Iterator<Item> {
        private Node current = last.next;

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

    public static void main(String[] args) { // Create a queue and enqueue/dequeue strings.
        CircularQueue<String> q = new CircularQueue<String>();
        while (!StdIn.isEmpty()) {
            String item = StdIn.readString();
            if (!item.equals("-"))
                q.enqueue(item);
            else if (!q.isEmpty()) StdOut.print(q.dequeue() + " ");
        }
        StdOut.println("(" + q.size() + " left on queue)");
    }

}
