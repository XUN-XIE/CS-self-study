/* *****************************************************************************
 *  Name:              Alan Turing
 *  Coursera User ID:  123456
 *  Last modified:     1/1/2019
 **************************************************************************** */

package Chapter3.Chapter3_1;

import edu.princeton.cs.algs4.ST;
import edu.princeton.cs.algs4.StdIn;
import edu.princeton.cs.algs4.StdOut;

public class Exercise1 {
    public static void main(String[] args) {
        ST<String, Double> st = new ST<String, Double>();
        String[] grades = new String[3];
        grades[0] = "A";
        grades[1] = "B";
        grades[2] = "C";
        for (int i = 4; i >= 2; i--) {
            double val1 = i + 0.33;
            double val2 = i - 0.33;
            double val3 = i;
            String word1 = grades[4 - i] + "+";
            String word2 = grades[4 - i] + "-";
            st.put(word1, val1);
            st.put(grades[4 - i], val3);
            st.put(word2, val2);
        }
        st.put("D", 1.0);
        st.put("F", 0.0);

        double scores = 0;
        int count = 0;
        while (!StdIn.isEmpty()) {
            String grade = StdIn.readString();
            scores += st.get(grade);
            count++;
        }
        StdOut.println(scores / count);
    }
}
