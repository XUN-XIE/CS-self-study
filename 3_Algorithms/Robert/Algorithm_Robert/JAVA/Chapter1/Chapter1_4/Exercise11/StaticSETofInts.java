/* *****************************************************************************
 *  Name:              Alan Turing
 *  Coursera User ID:  123456
 *  Last modified:     1/1/2019
 **************************************************************************** */

package Chapter1.Chapter1_4.Exercise11;

import edu.princeton.cs.algs4.In;
import edu.princeton.cs.algs4.StdIn;
import edu.princeton.cs.algs4.StdOut;

import java.util.Arrays;

public class StaticSETofInts {
    private int[] a;

    public StaticSETofInts(int[] keys) {
        a = new int[keys.length];
        for (int i = 0; i < keys.length; i++)
            a[i] = keys[i]; // defensive copy Arrays.sort(a);
    }

    public boolean contains(int key) {
        return rank(key) != -1;
    }

    private int rank(int key) { // Binary search.
        int lo = 0;
        int hi = a.length - 1;
        while (lo <= hi) { // Key is in a[lo..hi] or not present.
            int mid = lo + (hi - lo) / 2;
            if (key < a[mid]) hi = mid - 1;
            else if (key > a[mid]) lo = mid + 1;
            else return mid;
        }
        return -1;
    }

    public int howMany(int key) {
        int index = rank(key);
        if (index == -1)
            return 0;
        else {
            int count = 0;
            int right_index = index + 1;
            int left_index = index - 1;
            while (left_index >= 0 && a[left_index] == a[index]) {
                count++;
                left_index--;
            }
            while (right_index < a.length && a[right_index] == a[index]) {
                count++;
                right_index++;
            }

            return count;
        }
    }

    public static void main(String[] args) {
        In in = new In(args[0]);
        int[] w = in.readAllInts();
        Arrays.sort(w);
        StaticSETofInts set = new StaticSETofInts(w);

        while (!StdIn.isEmpty()) { // Read key, print if not in whitelist.
            int key = StdIn.readInt();
            if (set.howMany(key) != -1)
                StdOut.println(set.howMany(key));
        }
    }

}
