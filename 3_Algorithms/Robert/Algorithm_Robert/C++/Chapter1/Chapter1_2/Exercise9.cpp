#include "INCLUDE.hpp"

class Counter
{
public:
    Counter(string id) : name(id) { }
    void increment() { count++; }
    int tally() { return count; }

private:
    const string name;
    int count;
};

pair<vector<double>::const_iterator, int> binary_search(vector<double> & vec, double target)
{
    auto min_iter = vec.cbegin();
    auto max_iter = vec.cend();
    auto mid_iter = vec.cbegin() + (vec.cend() - vec.cbegin()) / 2;

    Counter count_times("count searches");
    while (min_iter != max_iter)
    {
        count_times.increment();
        if (target < *mid_iter)
        {
            // mention!!!! here need to add one to mid_iter!!! we do not need minus one because the max_iter, we will never touch the element in it
            max_iter = mid_iter;
            mid_iter = min_iter + (max_iter - min_iter) / 2;
        }
        else if (target > *mid_iter)
        {
            // mention!!!! here need to add one to mid_iter!!!
            min_iter = mid_iter + 1;
            mid_iter = mid_iter = min_iter + (max_iter - min_iter) / 2;
        }
        else
            return pair(mid_iter, count_times.tally());
    }
    return pair(vec.cend(), count_times.tally());
}

int main()
{
    ifstream infile("tinyW.txt");
    vector<double> vec = read_data(infile);

    sort(vec.begin(), vec.end());

    print(vec);

    double dou;

    while (cin >> dou)
    {
        auto pair = binary_search(vec, dou);
        if (pair.first != vec.cend())
            cout << *pair.first << " is found used " << pair.second << " times" << endl;
    }
}
