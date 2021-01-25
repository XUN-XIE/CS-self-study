/* *****************************************************************************
 *  Name:              Alan Turing
 *  Coursera User ID:  123456
 *  Last modified:     1/1/2019
 **************************************************************************** */

package Chapter1.Chapter1_3.Exercise11;

// my implementation is realized by C++

import edu.princeton.cs.algs4.StdIn;
import edu.princeton.cs.algs4.StdOut;

// this is the answer from booksite
public class EvaluatePostfix {
    public static void main(String[] args) {
        Stack<Integer> stack = new Stack<Integer>();

        while (!StdIn.isEmpty()) {
            String s = StdIn.readString();
            if (s.equals("+")) stack.push(stack.pop() + stack.pop());
            else if (s.equals("*")) stack.push(stack.pop() * stack.pop());
            else stack.push(Integer.parseInt(s));
        }
        StdOut.println(stack.pop());
    }
}
