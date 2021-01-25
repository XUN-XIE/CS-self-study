/* *****************************************************************************
 *  Name:              Alan Turing
 *  Coursera User ID:  123456
 *  Last modified:     1/1/2019
 **************************************************************************** */

package Chapter1.Chapter1_2;

import edu.princeton.cs.algs4.StdOut;

public class Exercise4 {
    public static void main(String[] args) {
        String origin = "ACTGACG", circular = "TGACGAC";
        StdOut.println(circular_rotation(origin, circular));
    }

    // 这题的的答案是从网上看的......
    public static boolean circular_rotation(String str1, String str2) {
        return (str1.length() == str2.length() && str1.concat(str1).indexOf(str2) != -1);
    }
}
