/* *****************************************************************************
 *  Name:              Alan Turing
 *  Coursera User ID:  123456
 *  Last modified:     1/1/2019
 **************************************************************************** */

package Chapter3.Chapter3_1;

import Chapter3.Chapter3_1.知识点.BinarySearchST;
import Chapter3.Chapter3_1.知识点.SequentialSearchST;
import edu.princeton.cs.algs4.StdOut;
import edu.princeton.cs.algs4.StdRandom;
import edu.princeton.cs.algs4.Stopwatch;

public class Exercise14 {
    public static void main(String[] args) {
        SequentialSearchST<Integer, Integer> ST = new SequentialSearchST<Integer, Integer>();
        BinarySearchST<Integer, Integer> BT = new BinarySearchST<Integer, Integer>(1000010);

        // this process takes too much time, so I set bound lower to test.
        // but the result is not so evident to prove that SequentialST is better.
        Stopwatch ST_timer = new Stopwatch();
        for (int i = 0; i < 1E5; i++) {
            if (StdRandom.uniform() < (1E3 / (1E6 + 1E3)))
                ST.get(i);
            else
                ST.put(i, 0);
        }
        double ST_consume = ST_timer.elapsedTime();

        Stopwatch BT_timer = new Stopwatch();
        for (int i = 0; i < 1E5; i++) {
            if (StdRandom.uniform() < (1E3 / (1E6 + 1E3)))
                BT.get(i);
            else
                BT.put(i, 0);
        }
        double BT_consume = ST_timer.elapsedTime();

        StdOut.println("ST :" + Double.toString(ST_consume));
        StdOut.println("BT :" + Double.toString(BT_consume));
    }
}
