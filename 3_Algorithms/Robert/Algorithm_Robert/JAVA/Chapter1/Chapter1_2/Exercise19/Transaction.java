/* *****************************************************************************
 *  Name:              Alan Turing
 *  Coursera User ID:  123456
 *  Last modified:     1/1/2019
 **************************************************************************** */

package Chapter1.Chapter1_2.Exercise19;

// import Chapter1.Chapter1_2.Exercise19.Date;

public class Transaction {
    // 用public不太符合工程标准，但是这个class写过很多次了，这里是为了方便输出测试
    public String customer;
    public Date date;
    public double amount;

    Transaction(String transaction) {
        String[] fields = transaction.split(" ");
        customer = fields[0];
        date = new Date(fields[1]);
        amount = Double.parseDouble(fields[2]);
    }

    public static void main(String[] args) {
        String test = "Turing 5/22/1939 11.99";
        Transaction test_T = Transaction(test);

        System.out.println(
                "custormer is " + test_T.customer + "\ndate is " + test_T.date.month + "\\"
                        + test_T.date.day + "\\" + test_T.date.year + "\namount is "
                        + test_T.amount);
    }
}
