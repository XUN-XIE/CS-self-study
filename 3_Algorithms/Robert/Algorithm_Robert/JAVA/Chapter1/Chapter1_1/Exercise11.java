/* *****************************************************************************
 *  Name:              Alan Turing
 *  Coursera User ID:  123456
 *  Last modified:     1/1/2019
 **************************************************************************** */

package Chapter1.Chapter1_1;

public class Exercise11 {
    public static void main(String[] args) {
        boolean[][] arrays = new boolean[10][10];
        for (int i = 0; i < 10; i++)
            for (int j = 0; j < 10; j++)
                arrays[i][j] = ((i + j) % 2 == 1) ? true : false;

        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < 10; j++) {
                System.out.print(arrays[i][j]);
                System.out.print("\t");
            }
            System.out.print("\n");
        }
    }
}
