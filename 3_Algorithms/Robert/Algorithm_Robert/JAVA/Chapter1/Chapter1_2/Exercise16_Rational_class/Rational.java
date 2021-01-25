/* *****************************************************************************
 *  Name:              Alan Turing
 *  Coursera User ID:  123456
 *  Last modified:     1/1/2019
 **************************************************************************** */

package Chapter1.Chapter1_2.Exercise16_Rational_class;

import edu.princeton.cs.algs4.StdOut;

public class Rational {
    private long numerator;
    private long denominator;

    Rational(long n, long d) {
        numerator = n;
        denominator = d;
    }

    public static long gcd(long p, long q) {
        if (q == 0)
            return p;
        long r = p % q;
        return gcd(q, r);
    }

    public Rational plus(Rational b) {
        long new_denominator = denominator * b.denominator;
        long new_numerator = numerator * b.denominator + b.numerator * denominator;

        return check_factor(new_numerator, new_denominator);
    }

    public Rational minus(Rational b) {
        long new_denominator = denominator * b.denominator;
        long new_numerator = numerator * b.denominator - b.numerator * denominator;

        return check_factor(new_numerator, new_denominator);
    }

    public Rational times(Rational b) {
        long new_denominator = denominator * b.denominator;
        long new_numerator = numerator * b.numerator;

        return check_factor(new_numerator, new_denominator);
    }

    public Rational divides(Rational b) {
        long new_denominator = denominator * b.numerator;
        long new_numerator = numerator * b.denominator;

        return check_factor(new_numerator, new_denominator);
    }

    private Rational check_factor(long new_numerator, long new_denominator) {
        long max_facor = gcd(new_denominator > new_numerator ? new_denominator : new_numerator,
                             new_numerator < new_denominator ? new_numerator : new_denominator);

        if (max_facor != 1) {
            new_denominator /= max_facor;
            new_numerator /= max_facor;
        }

        Rational result = new Rational(new_numerator, new_denominator);
        return result;
    }

    public void check_factor() {
        long max_facor = gcd(denominator > numerator ? denominator : numerator,
                             numerator < denominator ? numerator : denominator);

        if (max_facor != 1) {
            denominator /= max_facor;
            numerator /= max_facor;
        }
    }

    public long get_numerator() {
        return numerator;
    }

    public long get_denominator() {
        return denominator;
    }

    public boolean equals(Object x) {
        if (this == x) return true;
        if (x == null) return false;
        if (this.getClass() != x.getClass()) return false;
        Rational that = (Rational) x;
        this.check_factor();
        that.check_factor();
        if (this.numerator != that.get_numerator()) return false;
        if (this.denominator != that.get_denominator()) return false;
        return true;
    }

    public String toString() {
        if (numerator < 0 || denominator < 0)
            return "-" + Math.abs(get_numerator()) + "/" + Math.abs(get_denominator());
        return get_numerator() + "/" + get_denominator();
    }

    public static void main(String[] args) {
        // test case from booksite websit: https://algs4.cs.princeton.edu/12oop/Rational.java.html
        Rational x, y, z;

        // 1/2 + 1/3 = 5/6
        x = new Rational(1, 2);
        y = new Rational(1, 3);
        z = x.plus(y);
        StdOut.println(z);

        // 8/9 + 1/9 = 1
        x = new Rational(8, 9);
        y = new Rational(1, 9);
        z = x.plus(y);
        StdOut.println(z);

        // 1/200000000 + 1/300000000 = 1/120000000
        x = new Rational(1, 200000000);
        y = new Rational(1, 300000000);
        z = x.plus(y);
        StdOut.println(z);

        // 1073741789/20 + 1073741789/30 = 1073741789/12
        x = new Rational(1073741789, 20);
        y = new Rational(1073741789, 30);
        z = x.plus(y);
        StdOut.println(z);

        //  4/17 * 17/4 = 1
        x = new Rational(4, 17);
        y = new Rational(17, 4);
        z = x.times(y);
        StdOut.println(z);

        // 3037141/3247033 * 3037547/3246599 = 841/961
        x = new Rational(3037141, 3247033);
        y = new Rational(3037547, 3246599);
        z = x.times(y);
        StdOut.println(z);

        // 1/6 - -4/-8 = -1/3
        x = new Rational(1, 6);
        y = new Rational(-4, -8);
        z = x.minus(y);
        StdOut.println(z);
    }
}
