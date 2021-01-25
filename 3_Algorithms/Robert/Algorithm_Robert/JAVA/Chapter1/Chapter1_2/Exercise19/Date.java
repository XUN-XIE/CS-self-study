/* *****************************************************************************
 *  Name:              Alan Turing
 *  Coursera User ID:  123456
 *  Last modified:     1/1/2019
 **************************************************************************** */

package Chapter1.Chapter1_2.Exercise19;

public class Date {
    // 用public不太符合工程标准，但是这个class写过很多次了，这里是为了方便输出测试
    public int month;
    public int day;
    public int year;

    public Date(String date) {
        String[] fields = date.split("/");
        month = Integer.parseInt(fields[0]);
        day = Integer.parseInt(fields[1]);
        year = Integer.parseInt(fields[2]);
    }
}
