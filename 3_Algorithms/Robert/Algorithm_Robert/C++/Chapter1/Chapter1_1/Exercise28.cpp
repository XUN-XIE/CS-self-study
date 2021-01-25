#include "INCLUDE.hpp"

vector<double>::const_iterator binary_search(vector<double> & vec, double target);

int main()
{
    ifstream infile("tinyW.txt");
    vector<double> vec = read_data(infile);

    sort(vec.begin(), vec.end());
    auto iter = unique(vec.begin(), vec.end());
    vec.erase(iter, vec.end());

    print(vec);

    double dou;
    ofstream outfile("tinyT.txt", ios::app);
    while (cin >> dou)
    {
        auto iter_index = binary_search(vec, dou);
        if (iter_index != vec.cend())
            print_to_file(outfile, (int)(iter_index - vec.cbegin()));
    }
}

// vector must be sorted to pass through the function
vector<double>::const_iterator binary_search(vector<double> & vec, double target)
{
    auto min_iter = vec.cbegin();
    auto max_iter = vec.cend();
    auto mid_iter = vec.cbegin() + (vec.cend() - vec.cbegin()) / 2;

    while (min_iter != max_iter)
    {
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
            return mid_iter;
    }
    return (vec.cend());
}