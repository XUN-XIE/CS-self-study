/* *****************************************************************************
 *  Name:              Alan Turing
 *  Coursera User ID:  123456
 *  Last modified:     1/1/2019
 **************************************************************************** */

package Chapter1.Chapter1_4.Exercise10;

import edu.princeton.cs.algs4.In;
import edu.princeton.cs.algs4.StdIn;
import edu.princeton.cs.algs4.StdOut;

import java.util.Arrays;

public class BinarySearchSmall {
    private static int indexOf_once(int[] a, int key) {
        int lo = 0;
        int hi = a.length - 1;
        while (lo <= hi) {
            // Key is in a[lo..hi] or not present.
            int mid = lo + (hi - lo) / 2;
            if (key < a[mid]) hi = mid - 1;
            else if (key > a[mid]) lo = mid + 1;
            else return mid;
        }
        return -1;
    }

    public static int indexOf(int[] arr, int key) {
        int[] a = new int[arr.length];
        for (int i = 0; i < arr.length; i++)
            a[i] = arr[i];

        int small_index = a.length;
        int index = a.length;
        while (true) {
            index = indexOf_once(a, key);
            if (index == -1)
                break;

            int tmp_index = index;
            while (tmp_index < a.length - 1) {
                a[tmp_index] = a[tmp_index + 1];
                tmp_index++;
            }

            small_index = small_index < index ? small_index : index;
        }
        if (small_index == arr.length + 1)
            return -1;
        else
            return small_index;
    }


    public static void main(String[] args) {
        // read the integers from a file
        In in = new In(args[0]);
        int[] allowlist = in.readAllInts();

        // sort the array
        Arrays.sort(allowlist);

        // read integer key from standard input; print if not in allowlist
        while (!StdIn.isEmpty()) {
            int key = StdIn.readInt();
            double index = indexOf_once(allowlist, key);
            if (index != -1)
                StdOut.println(index);
        }
    }
}
