/* *****************************************************************************
 *  Name:              Alan Turing
 *  Coursera User ID:  123456
 *  Last modified:     1/1/2019
 **************************************************************************** */

package Chapter3.Chapter3_1.Exercise19;

import edu.princeton.cs.algs4.In;
import edu.princeton.cs.algs4.ST;
import edu.princeton.cs.algs4.StdOut;

public class FrequencyCounter {
    public static void main(String[] args) {
        int minlen = Integer.parseInt(args[0]);     // key-length cutoff
        ST<String, Integer> st = new ST<String, Integer>();

        In file = new In(args[1]);
        while (!file.isEmpty()) { // Build symbol table and count frequencies.
            String word = file.readString();
            // StdOut.println(word);
            if (word.length() < minlen)
                continue; // Ignore short keys. if (!st.contains(word)) st.put(word, 1);
            if (!st.contains(word)) st.put(word, 1);
            else st.put(word, st.get(word) + 1);
        }


        // Find a key with the highest frequency count.
        int max_count = 0;
        int prev_count = 0;
        while (true) {
            String max = "";
            st.put(max, 0);

            for (String word : st.keys())
                if (st.get(word) > st.get(max))
                    max = word;

            max_count = st.get(max);
            st.delete(max);
            if (max_count == prev_count || prev_count == 0)
                StdOut.println(max + " " + max_count);
            else
                break;
            prev_count = max_count;
        }
    }
}
