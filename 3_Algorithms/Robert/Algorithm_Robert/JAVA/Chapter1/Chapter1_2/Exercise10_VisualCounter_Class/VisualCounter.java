/* *****************************************************************************
 *  Name:              Alan Turing
 *  Coursera User ID:  123456
 *  Last modified:     1/1/2019
 **************************************************************************** */

package Chapter1.Chapter1_2.Exercise10_VisualCounter_Class;

import edu.princeton.cs.algs4.StdDraw;
import edu.princeton.cs.algs4.StdRandom;

public class VisualCounter {
    final private int num_oper;
    private double max_abs;
    private int count;

    public VisualCounter(int N, double max) {
        num_oper = N;
        max_abs = max;
    }

    public void increment() {
        if (Math.abs(count) < max_abs)
            count++;
    }

    public void decrement() {
        if (Math.abs(count) < max_abs)
            count--;
    }

    public int tally() {
        return count;
    }

    public void visualize() {
        for (int i = 0; i < num_oper; i++) {
            if (StdRandom.uniform() < 0.5)
                decrement();
            else
                increment();
            StdDraw.point(i, count);
        }
    }

    public static void main(String[] args) {
        int N = Integer.parseInt(args[0]);
        double max = Double.parseDouble(args[1]);

        StdDraw.setXscale(-5, N + 5);
        StdDraw.setYscale(-max - 5, max + 5);
        StdDraw.setPenRadius(0.01);

        VisualCounter counter = new VisualCounter(N, max);

        counter.visualize();
    }
}
