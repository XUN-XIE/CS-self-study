/* *****************************************************************************
 *  Name:              Alan Turing
 *  Coursera User ID:  123456
 *  Last modified:     1/1/2019
 **************************************************************************** */

package Chapter1.Chapter1_4.Exercise8;

import Chapter1.Chapter1_4.知识点.Stopwatch;
import edu.princeton.cs.algs4.StdOut;
import edu.princeton.cs.algs4.StdRandom;

import java.util.Arrays;

public class TwoEqual {
    public static double timeTrial(int N) { // Time ThreeSum.count() for N random 6-digit ints.
        int MAX = 100;
        int[] a = new int[N];
        for (int i = 0; i < N; i++)
            a[i] = StdRandom.uniform(-MAX, MAX);
        Stopwatch timer = new Stopwatch();
        int cnt = best_count(a);
        return timer.elapsedTime();
    }

    public static int brute_count(int[] arr) {
        int N = arr.length;
        int cnt = 0;
        for (int i = 0; i < N; i++)
            for (int j = i + 1; j < N; j++)
                if (arr[i] == arr[j])
                    cnt++;
        return cnt;
    }

    // 1Mints.txt属于全不等序列，因此属于特殊的array，进行fast_count，内循环都直接跳出了！！！
    // 如果再考虑特殊情况，全等数列，那么这个fast count需要 ～N^2/2 。
    // 因此使用随机数生成array测试。
    // 结论：当序列中相等的数据越少，时间复杂度趋近于 linearithmic （因为排序算法）
    // 当序列中相等的数据越多，时间复杂度趋近于quadratic
    public static int fast_count(int[] arr) {
        Arrays.sort(arr);
        int N = arr.length;
        int cnt = 0;
        for (int i = 0; i < N - 1; i++)
            if (arr[i] == arr[i + 1]) {
                cnt++;
                if (i == N - 2)
                    break;
                int index = i + 2;
                while (index < N && arr[i] == arr[index]) {
                    cnt++;
                    index++;
                }
            }
        return cnt;
    }

    // 借助了数学方法，因此速度是最快的，因为lower bound比fast_count高的多
    // 时间复杂度是 linearithmic ！！！，不存在不稳定情况
    public static int best_count(int[] arr) {
        Arrays.sort(arr);
        int N = arr.length;
        int cnt = 0;
        for (int i = 0; i < N - 1; )
            if (arr[i] == arr[i + 1]) {
                int count_equal_phase = 2;
                int index = i + 2;
                while (index < N && arr[i] == arr[index]) {
                    count_equal_phase++;
                    index++;
                }
                cnt += (count_equal_phase * (count_equal_phase - 1)) / 2;
                i = index;
            }
        return cnt;
    }

    public static void main(String[] args) {
        for (int N = 160000; N < 160000 * 32 + 1; N += N) { // Print time for problem size N.
            double time = timeTrial(N);
            StdOut.printf("%7d %5.3f\n", N, time);
        }


        // Stopwatch timer1 = new Stopwatch();
        // StdOut.println(fast_count(a));
        // double time_con1 = timer1.elapsedTime();
        // StdOut.println("fast count spent " + time_con1 + " seconds");


        // Stopwatch timer2 = new Stopwatch();
        // StdOut.println(brute_count(a));
        // double time_con2 = timer2.elapsedTime();
        // StdOut.println("fast count spent " + time_con2 + " seconds");
    }
}
