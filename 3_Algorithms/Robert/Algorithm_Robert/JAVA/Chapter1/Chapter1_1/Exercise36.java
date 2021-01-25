/* *****************************************************************************
 *  Name:              Alan Turing
 *  Coursera User ID:  123456
 *  Last modified:     1/1/2019
 **************************************************************************** */

package Chapter1.Chapter1_1;

import edu.princeton.cs.algs4.StdRandom;

public class Exercise36 {
    public static void main(String[] args) {
        int M = Integer.parseInt(args[0]), N = Integer.parseInt(args[1]);
        int[] arr = new int[M];
        int[][] count = new int[M][M];

        for (int times = 0; times < N; times++) {
            for (int i = 0; i < M; i++) {
                arr[i] = i;

            }
            StdRandom.shuffle(arr);
            for (int j = 0; j < M; j++) {
                int position = arr[j];
                count[position][j]++;
            }
        }

        for (int i = 0; i < M; i++) {
            for (int j = 0; j < M; j++) {
                System.out.print(count[i][j]);
                System.out.print(" ");
            }
            System.out.print("\n");
        }
    }

}
