/* *****************************************************************************
 *  Name:              Alan Turing
 *  Coursera User ID:  123456
 *  Last modified:     1/1/2019
 **************************************************************************** */

package Chapter1.Chapter1_2;

import edu.princeton.cs.algs4.Interval1D;
import edu.princeton.cs.algs4.Interval2D;
import edu.princeton.cs.algs4.StdDraw;
import edu.princeton.cs.algs4.StdOut;
import edu.princeton.cs.algs4.StdRandom;

public class Exercise3 {
    public static void main(String[] args) {
        int N = Integer.parseInt(args[0]);
        double min = Double.parseDouble(args[1]);
        double max = Double.parseDouble(args[2]);

        StdDraw.setXscale(min - 10, max + 10);
        StdDraw.setYscale(min - 10, max + 10);
        StdDraw.setPenRadius(0.005);

        Interval2D[] interval_arr = new Interval2D[N];
        for (int i = 0; i < N; i++) {
            double x1 = StdRandom.uniform(min, max), x2 = StdRandom.uniform(min, max);
            double y1 = StdRandom.uniform(min, max), y2 = StdRandom.uniform(min, max);
            Interval1D inter1 = new Interval1D(x1 < y1 ? x1 : y1, y1 > x1 ? y1 : x1);
            Interval1D inter2 = new Interval1D(x2 < y2 ? x2 : y2, y2 > x2 ? y2 : x2);
            interval_arr[i] = new Interval2D(inter1, inter2);
            interval_arr[i].draw();
        }

        int count_intesect = 0;
        for (int i = 1; i < N; i++) {
            for (int j = 0; j < i; j++) {
                if (interval_arr[i].intersects(interval_arr[j]))
                    count_intesect++;
            }
        }

        StdOut.println("number of intersects: " + count_intesect);

    }
}
