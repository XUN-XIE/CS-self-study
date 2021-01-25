/* *****************************************************************************
 *  Name:              Alan Turing
 *  Coursera User ID:  123456
 *  Last modified:     1/1/2019
 **************************************************************************** */

package Chapter1.Chapter1_2.知识点;

import edu.princeton.cs.algs4.StdOut;

// 思想！同一个class的实现有不同的方式，针对的是不同的时间和空间需求
// 比如这个版本的Date，在空间上就占用的少，因为只用了一个int值存储数据
// 但是时间上要求高，因为调用方法的时候需要计算
public class SmallDate {
    private final int value;

    public SmallDate(int m, int d, int y) {
        value = y * 512 + m * 32 + d;
    }

    public int month() {
        return (value / 32) % 16;
    }

    public int day() {
        return value % 32;
    }

    public int year() {
        return value / 512;
    }

    public String toString() {
        return month() + "/" + day() + "/" + year();
    }

    public static void main(String[] args) {
        int m = Integer.parseInt(args[0]);
        int d = Integer.parseInt(args[1]);
        int y = Integer.parseInt(args[2]);
        SmallDate date = new SmallDate(m, d, y);
        StdOut.println(date);
    }

}

