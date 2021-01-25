/* *****************************************************************************
 *  Name:              Alan Turing
 *  Coursera User ID:  123456
 *  Last modified:     1/1/2019
 **************************************************************************** */

package Chapter1.Chapter1_1;

public class Exercise13 {
    public static int[][] transposition(int[][] arrays, int rows, int cols) {
        int[][] transposed = new int[cols][rows];
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++)
                transposed[j][i] = arrays[i][j];
        }
        return transposed;
    }

    public static void main(String[] args) {
        int[][] arrays = new int[20][10];
        int rows = 20, cols = 10;

        int count = 0;
        for (int i = 0; i < rows; i++)
            for (int j = 0; j < cols; j++)
                arrays[i][j] = count++;

        int[][] transposed = transposition(arrays, 20, 10);
        for (int i = 0; i < cols; i++) {
            for (int j = 0; j < rows; j++) {
                System.out.print(transposed[i][j]);
                System.out.print("\t");
            }
            System.out.print("\n");
        }
    }
}
