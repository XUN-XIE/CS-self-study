/* *****************************************************************************
 *  Name:              Alan Turing
 *  Coursera User ID:  123456
 *  Last modified:     1/1/2019
 **************************************************************************** */

package Chapter1.Chapter1_3.Exercise_linked_list;

public class LinkedList<Item> {
    private Node first; // top of stack (most recently added node)
    private int N;      // number of items

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

    public void push_front(Item val) {
        Node addition = new Node();
        addition.item = val;
        addition.next = first;
        first = addition;
        N++;
    }

    // Exercise 19
    public Item pop() {
        if (!isEmpty()) {
            Node prev = null;
            Node curr = first;
            while (curr.next != null) {
                prev = curr;
                curr = curr.next;
            }
            N--;

            if (prev != null) {
                prev.next = null;
                return curr.item;
            }
            else {
                Item result = first.item;
                first = null;
                return result;
            }
        }
        // 不报错，选择返回null，因为我不会JAVA报错代码
        else
            return null;
    }

    // Exercise 20  这个比较难写，因为处理特殊情况比较麻烦，比如只有一个Node时删除第0个元素，容易出bug
    public Item delete(int k) {
        if (!isEmpty()) {
            Node prev = null;
            Node curr = first;
            int count = 0;

            while (count < k) {
                if (curr.next == null)
                    return null;
                prev = curr;
                curr = curr.next;
                count++;
            }

            if (k == 0) {
                if (first.next == null) {
                    Item result = first.item;
                    first = null;
                    return result;
                }
                else {
                    Item result = curr.item;
                    first = first.next;
                    return result;
                }
            }

            Item result = curr.item;
            prev.next = curr.next;
            return result;
        }
        else
            return null;
    }

    // Exercise21
    public boolean find(Item val) {
        if (!isEmpty()) {
            Node prev = null;
            Node curr = first;
            while (curr != null) {
                if (curr.item == val)
                    return true;
                prev = curr;
                curr = curr.next;
            }
            return false;
        }
        else
            return false;
    }

    // Exercise 24, Node 是内置范型，无法赋值，无法测试
    public void removeAfter(Node target) {
        if (target == null || target.next == null)
            return;
        if (!isEmpty()) {
            Node prev = null;
            Node curr = first;
            while (curr != target && curr.next != null) {
                prev = curr;
                curr = curr.next;
            }

            if (curr == target) {
                curr.next = null;
            }
        }
    }

    // public void test_removeAfter() {
    //     LinkedList<Integer> test = new LinkedList<Integer>();
    //     test.push_front(1);
    //     test.push_front(2);
    //     test.push_front(3);
    //     Node target = new Node();
    //     target.item = 1;
    //     target.next = null;
    //     removeAfter(target);
    //
    //     for (int i = 0; i < 5; i++)
    //         StdOut.println(test.pop());
    // }

    // Exercie25, 同Exercise24，无法测试
    public void insertAfter(Node node1, Node node2) {
        if (node1 == null || node2 == null)
            return;
        if (!isEmpty()) {
            Node prev = null;
            Node curr = first;
            while (curr != node1) {
                prev = curr;
                curr = curr.next;
            }
            node2.next = curr.next;
            curr.next = node2;
        }
        return;
    }

    // Exercise26
    public void remove(Item key) {
        Node prev = null;
        Node curr = first;
        int count = 0;
        while (curr.next != null) {
            if (curr.item == key) {
                if (prev == null) {
                    curr = curr.next;
                    first = curr;
                    continue;
                }
                else {
                    prev.next = curr.next;
                    curr = curr.next;
                    continue;
                }
            }
            prev = curr;
            curr = curr.next;
        }
        if (curr.item == key) {
            prev.next = curr.next;
            curr = curr.next;
        }
    }

    // // Exercise27
    // // 如果是static不能访问 Node
    // // 如果不是static，因为是泛型编程，不能使用Item和Integer比较大小
    // public int max() {
    //         if (isEmpty())
    //             return 0;
    //     double max_item = (Double.NEGATIVE_INFINITY);
    //
    //     Node prev = null;
    //     Node curr = first;
    //     while (curr.next != null) {
    //         if (curr.item > max_item)
    //             max_item = curr.item;
    //
    //         prev = curr;
    //         curr = curr.next;
    //     }
    //
    //     if (curr.item > max_item)
    //         max_item = curr.item;
    //
    //     return max_item;
    // }

    // // Exercise28
    // // 同上一题的问题，只写出大概的代码
    // public int max_recur() {
    //     if (isEmpty())
    //         return 0;
    //     double max_item = (Double.NEGATIVE_INFINITY);
    //     if (first.next == null)
    //         return max_item > first.item ? max_item : first.item;
    //
    //     Node prev = null;
    //     Node curr = first;
    //     return max_recur(curr, curr.next, max_item > curr.item ? max_item : curr.item);
    // }
    //
    // public int max_recur(Node prev, Node curr, int max_item) {
    //     if (isEmpty())
    //         return 0;
    //     if (curr.next == null)
    //         return max_item > curr.item ? max_item : curr.item;
    //     return max_recur(curr, curr.next, max_item > curr.item ? max_item : curr.item);
    // }

    public Node reverse() {
        Node[] node_arr = new Node[size()];
        Node curr = first;

        int count = 0;
        while (curr.next != null) {
            node_arr[count] = curr;
            count++;
            curr = curr.next;
        }

        for (int i = size() - 1; i > 0; i++) {
            node_arr[i].next = node_arr[i - 1];
        }
        node_arr[0].next = null;

        return node_arr[size() - 1];
    }

    public void test_reverse() {
        LinkedList<Integer> test = new LinkedList<Integer>();
        test.push_front(1);
        test.push_front(2);
        test.push_front(1);
    }

    public static void main(String[] args) {
        // LinkedList<String> test = new LinkedList<String>();
        // test.push_front("xie");
        // test.push_front("xun");
        // test.push_front("xie");
        //
        // test.remove("xie");
        // for (int i = 0; i < 5; i++)
        //     StdOut.println(test.pop());

        LinkedList<Integer> test = new LinkedList<Integer>();
        test.push_front(1);
        test.push_front(2);
        test.push_front(1);

    }
}
