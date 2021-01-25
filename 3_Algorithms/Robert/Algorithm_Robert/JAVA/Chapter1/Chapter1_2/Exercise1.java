/* *****************************************************************************
 *  Name:              Alan Turing
 *  Coursera User ID:  123456
 *  Last modified:     1/1/2019
 **************************************************************************** */

package Chapter1.Chapter1_2;

import edu.princeton.cs.algs4.Point2D;
import edu.princeton.cs.algs4.StdOut;
import edu.princeton.cs.algs4.StdRandom;

public class Exercise1 {
    public static void main(String[] args) {
        int N = Integer.parseInt(args[0]);

        Point2D[] point_arr = new Point2D[N];
        for (int i = 0; i < N; i++) {
            StdRandom.uniform();
            point_arr[i] = new Point2D(StdRandom.uniform(), StdRandom.uniform());
        }

        double min_dis = Double.POSITIVE_INFINITY;
        for (int i = 1; i < N; i++) {
            for (int j = 0; j < i; j++) {
                double dis = point_arr[i].distanceTo(point_arr[j]);
                if (dis < min_dis)
                    min_dis = dis;
            }
        }

        StdOut.println(min_dis);
    }
}
