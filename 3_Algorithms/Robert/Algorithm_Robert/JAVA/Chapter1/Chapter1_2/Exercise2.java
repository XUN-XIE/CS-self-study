/* *****************************************************************************
 *  Name:              Alan Turing
 *  Coursera User ID:  123456
 *  Last modified:     1/1/2019
 **************************************************************************** */

package Chapter1.Chapter1_2;

import edu.princeton.cs.algs4.Interval1D;
import edu.princeton.cs.algs4.StdIn;
import edu.princeton.cs.algs4.StdOut;

public class Exercise2 {
    public static void main(String[] args) {
        int N = Integer.parseInt(args[0]);

        Interval1D[] interval_arr = new Interval1D[N];
        for (int i = 0; i < N; i++) {
            int x = StdIn.readInt();
            int y = StdIn.readInt();

            interval_arr[i] = new Interval1D(x, y);
        }

        for (int i = 1; i < N; i++) {
            for (int j = 0; j < i; j++) {
                if (interval_arr[i].intersects(interval_arr[j]))
                    StdOut.println(interval_arr[i] + "\t" + interval_arr[j]);
            }
        }
    }
}
