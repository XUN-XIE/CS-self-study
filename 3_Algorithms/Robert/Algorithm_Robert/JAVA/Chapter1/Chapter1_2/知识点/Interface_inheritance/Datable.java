/* *****************************************************************************
 *  Name:              Alan Turing
 *  Coursera User ID:  123456
 *  Last modified:     1/1/2019
 **************************************************************************** */

package Chapter1.Chapter1_2.知识点.Interface_inheritance;


// allows us to specify a relationship between otherwise unrelated classes by specifying in an interface
// a set of common methods that each implementing class must contain
public interface Datable {
    int month();

    int day();

    int year();
}
