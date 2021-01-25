/* *****************************************************************************
 *  Name:              Alan Turing
 *  Coursera User ID:  123456
 *  Last modified:     1/1/2019
 **************************************************************************** */

package Chapter1.Chapter1_3;

import Chapter1.Chapter1_2.Exercise19.Date;
import Chapter1.Chapter1_3.知识点.Queue;
import edu.princeton.cs.algs4.In;
import edu.princeton.cs.algs4.StdOut;


public class Exercise16 {
    public static int[] readInts(String name) {
        In in = new In(name);
        Queue<Integer> q = new Queue<Integer>();
        while (!in.isEmpty())
            q.enqueue(in.readInt());

        int N = q.size();
        int[] a = new int[N];
        for (int i = 0; i < N; i++)
            a[i] = q.dequeue();
        return a;
    }

    public static Date[] readDates(String name) {
        int[] all_ints = readInts(name);
        int size = all_ints.length / 3;

        Date[] date_arr = new Date[size];
        for (int i = 0; i < size; i++) {
            String arg1 = (Integer.toString(all_ints[3 * i]));
            String arg2 = (Integer.toString(all_ints[3 * i + 1]));
            String arg3 = (Integer.toString(all_ints[3 * i + 2]));
            String arg4 = "/";
            String arg = arg1 + arg4 + arg2 + arg4 + arg3;
            StdOut.println(arg);
            date_arr[i] = new Date(arg);
        }
        return date_arr;
    }


    public static void main(String[] args) {
        String filename = args[0];
        Date[] date_arr = readDates(filename);
    }
}
