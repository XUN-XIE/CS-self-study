/* *****************************************************************************
 *  Name:              Alan Turing
 *  Coursera User ID:  123456
 *  Last modified:     1/1/2019
 **************************************************************************** */

package Chapter3.Chapter3_1;

import edu.princeton.cs.algs4.ST;
import edu.princeton.cs.algs4.StdOut;
import edu.princeton.cs.algs4.StdRandom;

public class Exercise7 {
    public static void main(String[] args) {
        int test_time_for_average = Integer.parseInt(args[0]);
        for (int N = 10; N < 1E6 + 1; N *= 10) {
            // test ten times to compute average;
            double size = 0;
            for (int i = 0; i < test_time_for_average; i++) {
                ST<Integer, Integer> st = new ST<Integer, Integer>();
                for (int j = 0; j < N; j++) {
                    int value = StdRandom.uniform(0, 1000);
                    st.put(value, 1);
                }
                size += st.size();
            }
            double average_size = size / test_time_for_average;
            StdOut.println(
                    "N = " + Integer.toString(N) + ": size is: " + Double.toString(average_size));
        }
    }
}
