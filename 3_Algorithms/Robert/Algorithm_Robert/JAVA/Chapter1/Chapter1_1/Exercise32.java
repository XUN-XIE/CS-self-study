/* *****************************************************************************
 *  Name:              Alan Turing
 *  Coursera User ID:  123456
 *  Last modified:     1/1/2019
 **************************************************************************** */

package Chapter1.Chapter1_1;

import edu.princeton.cs.algs4.In;
import edu.princeton.cs.algs4.StdDraw;

public class Exercise32 {
    public static void main(String[] args) {
        int N = Integer.parseInt(args[0]);
        double l = Double.parseDouble(args[1]);
        double r = Double.parseDouble(args[2]);

        In file = new In("./Chapter1/Chapter1_1/mediumUF.txt");
        double[] sequence = file.readAllDoubles();

        int[] count_num = new int[N];
        double[] intervals = new double[N];
        for (int i = 0; i < N; i++) {
            intervals[i] = l + (r - l) * i / 10;
            System.out.print(intervals[i]);
            System.out.print("\t");
        }
        System.out.println("\n");


        for (int i = 0; i < sequence.length; i++) {
            double result = (sequence[i] - l) / ((r - l) / 10);
            int index = new Double(result).intValue();
            count_num[index] += 1;
        }

        for (int i = 0; i < 10; i++) {
            System.out.print(count_num[i]);
            System.out.print("\t");
        }


        StdDraw.setXscale(-5, 1005);
        StdDraw.setYscale(-5, 500);
        for (int i = 0; i < N; i++) {
            double x = intervals[i];
            double y = count_num[i] / 2.0;
            double rw = (intervals[1] - intervals[0] - 10) / 2;
            double rh = count_num[i] / 2.0;
            StdDraw.filledRectangle(x, y, rw, rh);
        }
    }
}
