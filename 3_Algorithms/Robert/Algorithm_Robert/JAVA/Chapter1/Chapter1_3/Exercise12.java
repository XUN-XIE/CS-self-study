/* *****************************************************************************
 *  Name:              Alan Turing
 *  Coursera User ID:  123456
 *  Last modified:     1/1/2019
 **************************************************************************** */

package Chapter1.Chapter1_3;

import Chapter1.Chapter1_3.知识点.Stack;
import edu.princeton.cs.algs4.StdOut;

public class Exercise12 {
    public static Stack<String> copy(Stack<String> str) {
        Stack<String> result = new Stack<String>();
        for (String ele : str)
            result.push(ele);

        return result;
    }


    public static void main(String[] args) {
        Stack<String> test = new Stack<String>();
        test.push("xie");
        Stack<String> result = copy(test);

        StdOut.println(result.pop());
        StdOut.println(test.pop());
    }
}
