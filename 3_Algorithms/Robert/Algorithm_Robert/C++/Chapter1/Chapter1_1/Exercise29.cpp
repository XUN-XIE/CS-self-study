#include "INCLUDE.hpp"

vector<double>::const_iterator binary_search(vector<double> & vec, double target);
int count_key(vector<double> & vec, double target);

int main()
{
    ifstream infile("tinyW.txt");
    vector<double> vec = read_data(infile);

    sort(vec.begin(), vec.end());

    print(vec);

    double dou;
    ofstream outfile("tinyT.txt", ios::app);
    while (cin >> dou)
    {
        auto left_iter = binary_search(vec, dou);
        int count_num = count_key(vec, dou);
        for(int i = 0; i < count_num; i++)
            cout << *left_iter++ << "\t";
        cout << endl;
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
        {
            auto left_iter = mid_iter;
            while(*(--left_iter) == *mid_iter)
            {}
            left_iter++;

            return left_iter;
        }
    }
    return vec.cend();
}

int count_key(vector<double> & vec, double target)
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
        {
            int count_num = 0;
            auto iter = mid_iter;
            while(*(iter--) == *mid_iter)
                count_num += 1;

            iter = mid_iter;
            while(*(++iter) == *mid_iter)
                count_num += 1;
            return count_num;
        }
    }
    return 0;
}