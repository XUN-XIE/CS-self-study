/* *****************************************************************************
 *  Name:              Alan Turing
 *  Coursera User ID:  123456
 *  Last modified:     1/1/2019
 **************************************************************************** */

package Chapter1.Chapter1_1;

import edu.princeton.cs.algs4.StdDraw;
import edu.princeton.cs.algs4.StdRandom;

public class Exercise31 {
    public static void main(String[] args) {
        int N = Integer.parseInt(args[0]);
        double p = Double.parseDouble(args[1]);

        StdDraw.setXscale(-5, N + 5);
        StdDraw.setYscale(-5, N + 5);

        int[] x_arr = new int[N];
        int[] y_arr = new int[N];
        for (int i = 0; i < N; i++) {
            int x = StdRandom.uniform(N), y = StdRandom.uniform(N);
            x_arr[i] = x;
            y_arr[i] = y;
            StdDraw.circle(x, y, 1);
        }

        for (int i = 0; i != N; i++) {
            for (int j = 0; j != i; j++) {
                if (StdRandom.uniform() < p) {
                    StdDraw.line(x_arr[i], y_arr[i], x_arr[j], y_arr[j]);
                }
            }
        }
    }
}
