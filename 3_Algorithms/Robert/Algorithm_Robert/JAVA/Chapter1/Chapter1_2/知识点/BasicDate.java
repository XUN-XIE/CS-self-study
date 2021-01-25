/* *****************************************************************************
 *  Name:              Alan Turing
 *  Coursera User ID:  123456
 *  Last modified:     1/1/2019
 **************************************************************************** */

package Chapter1.Chapter1_2.知识点;

import edu.princeton.cs.algs4.Date;
import edu.princeton.cs.algs4.StdOut;

// 思想！同一个class的实现有不同的方式，针对的是不同的时间和空间需求
// 比如这个版本的Date，在时间上就占用的少，因为方法调用直接返回值
// 但是空间上要求高，因为数据储存需要三个int值
public class BasicDate {
    private final int month;
    private final int day;
    private final int year;

    public BasicDate(int m, int d, int y) {
        month = m;
        day = d;
        year = y;
    }

    public int month() {
        return month;
    }

    public int day() {
        return day;
    }

    public int year() {
        return year;
    }

    public String toString() {
        return month() + "/" + day() + "/" + year();
    }

    public boolean equals(Object x) {
        if (this == x) return true;
        if (x == null) return false;
        if (this.getClass() != x.getClass()) return false;
        Date that = (Date) x;
        if (this.day != that.day()) return false;
        if (this.month != that.month()) return false;
        if (this.year != that.year()) return false;
        return true;
    }

    public static void main(String[] args) {
        int m = Integer.parseInt(args[0]);
        int d = Integer.parseInt(args[1]);
        int y = Integer.parseInt(args[2]);
        // assert m == 10 : "test";
        BasicDate date = new BasicDate(m, d, y);
        StdOut.println(date);
    }

}

