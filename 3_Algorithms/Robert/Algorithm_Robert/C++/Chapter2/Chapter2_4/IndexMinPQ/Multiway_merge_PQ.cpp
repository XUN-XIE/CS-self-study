#include "IndexMinPQ.hpp"

// 输出效果和书本不对应，因此检查失败
void merge(vector<string> filenames)
{
    IndexMinPQ<string> pq(24);
    int count = 0;
    for (int i = 0; i < 3; i++)
    {
        ifstream infile;
        infile.open(filenames[i]);
        string key;
        count++;
        while (infile >> key)
        {
            pq.insert(count, key);
        }
    }

    while (!pq.isEmpty())
    {
        cout << pq.minKey() << " ";
        int i = pq.delMin();
    }
}

int main()
{
    int N = 3;
    vector<string> filenames = {"m1.txt", "m2.txt", "m3.txt"};
    merge(filenames);
}