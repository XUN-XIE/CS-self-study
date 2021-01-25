#include "INCLUDE.hpp"

vector<double>::const_iterator binary_search(vector<double> & vec, double target);
vector<double>::const_iterator binary_search(vector<double>::const_iterator min_iter, vector<double>::const_iterator mid_iter, vector<double>::const_iterator max_iter, double target, vector<double>::const_iterator end_iter, int);
int main(int argc, char* argv[])
{
    ifstream infile("tinyW.txt");
    vector<double> vec = read_data(infile);

    sort(vec.begin(), vec.end());

    print(vec);

    double dou;
    ofstream outfile("tinyT.txt", ios::app);
    while (cin >> dou)
    {
        auto iter_index = binary_search(vec, dou);
        if (iter_index != vec.cend() && !string("-").compare(argv[1]))
            cout << *iter_index << endl;
        else if(iter_index == vec.cend() && !string("+").compare(argv[1]))
            cout << dou << endl;
            
    }
}

// vector must be sorted to pass through the function
vector<double>::const_iterator binary_search(vector<double> & vec, double target)
{
    auto min_iter = vec.cbegin();
    auto max_iter = vec.cend();
    auto mid_iter = vec.cbegin() + (vec.cend() - vec.cbegin()) / 2;
    int depth = -1;
    if (min_iter == max_iter)
        return vec.cend();

    if (target < *mid_iter)
    {
        max_iter = mid_iter;
        mid_iter = min_iter + (max_iter - min_iter) / 2;

        return binary_search(min_iter, mid_iter, max_iter, target, vec.cend(), depth);
    }
    else if (target > *mid_iter)
    {
        min_iter = mid_iter + 1;
        mid_iter = mid_iter = min_iter + (max_iter - min_iter) / 2;

        return binary_search(min_iter, mid_iter, max_iter, target, vec.cend(), depth);
    }
    else
        return mid_iter;
}

vector<double>::const_iterator binary_search(vector<double>::const_iterator min_iter, vector<double>::const_iterator mid_iter, vector<double>::const_iterator max_iter, double target, vector<double>::const_iterator end_iter, int depth)
{
    depth++;
    string indent(depth, '\t');
    if (min_iter == max_iter)
        return end_iter;
    if (target < *mid_iter)
    {
        // mention!!!! here need to add one to mid_iter!!! we do not need minus one because the max_iter, we will never touch the element in it
        max_iter = mid_iter;
        mid_iter = min_iter + (max_iter - min_iter) / 2;

        cout << indent << *mid_iter << "\t" << *max_iter << endl;
        return binary_search(min_iter, mid_iter, max_iter, target, end_iter, depth);
    }
    else if (target > *mid_iter)
    {
         // mention!!!! here need to add one to mid_iter!!!
        min_iter = mid_iter + 1;
        mid_iter = mid_iter = min_iter + (max_iter - min_iter) / 2;

        cout << indent << *mid_iter << "\t" << *max_iter << endl;
        return binary_search(min_iter, mid_iter, max_iter, target, end_iter, depth);
    }
    else
        return mid_iter;
}