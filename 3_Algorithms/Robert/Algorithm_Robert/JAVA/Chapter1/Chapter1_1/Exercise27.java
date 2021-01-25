/* *****************************************************************************
 *  Name:              Alan Turing
 *  Coursera User ID:  123456
 *  Last modified:     1/1/2019
 **************************************************************************** */

package Chapter1.Chapter1_1;

public class Exercise27 {
    public static void main(String[] args) {
        System.out.println(binomial(10, 7, 0.7));
    }

    public static double binomial(int N, int k, double p) {
        if ((N == 0) || (k < 0)) return 1.0;
        return (1.0 - p) * binomial(N - 1, k, p) + p * binomial(N - 1, k - 1, p);
    }
}
