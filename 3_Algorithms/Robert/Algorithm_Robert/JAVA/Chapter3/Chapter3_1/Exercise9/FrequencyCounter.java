/* *****************************************************************************
 *  Name:              Alan Turing
 *  Coursera User ID:  123456
 *  Last modified:     1/1/2019
 **************************************************************************** */

package Chapter3.Chapter3_1.Exercise9;

import edu.princeton.cs.algs4.In;
import edu.princeton.cs.algs4.ST;
import edu.princeton.cs.algs4.StdOut;

public class FrequencyCounter {
    public static void main(String[] args) {
        int minlen = Integer.parseInt(args[0]);     // key-length cutoff
        ST<String, Integer> st = new ST<String, Integer>();

        int count = 0;
        String record_last = "";
        In file = new In(args[1]);
        while (!file.isEmpty()) { // Build symbol table and count frequencies.
            String word = file.readString();
            // StdOut.println(word);
            if (word.length() < minlen)
                continue; // Ignore short keys. if (!st.contains(word)) st.put(word, 1);
            if (!st.contains(word)) {
                st.put(word, 1);
                record_last = word;
                count++;
            }
            else {
                st.put(word, st.get(word) + 1);
                count++;
            }
        }

        StdOut.println("last word inserted is : " + record_last);
        StdOut.println("there are " + Integer.toString(count) + " words were inserted before");


        // Find a key with the highest frequency count.
        String max = "";
        st.put(max, 0);

        for (String word : st.keys())
            if (st.get(word) > st.get(max))
                max = word;
        StdOut.println(max + " " + st.get(max));
    }
}

