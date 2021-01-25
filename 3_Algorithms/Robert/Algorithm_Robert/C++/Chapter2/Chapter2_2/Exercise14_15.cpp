#include "../AllSort.hpp"
#include <queue>

queue<int> Merge_queue(queue<int> & que1, queue<int> & que2)
{
    queue<int> result;
    while (!que1.empty() && ! que2.empty())
    {
        int val1 = que1.front();
        int val2 = que2.front();
        if (val1 > val2)
        {
            result.push(val2);
            que2.pop();
        }
        else
        {
            result.push(val1);
            que1.pop();
        }
    }
    if (que1.empty())
    {
        while (!que2.empty())
        {
            result.push(que2.front());
            que2.pop();
        }
    }
    if (que2.empty())
    {
        while (!que1.empty())
        {
            result.push(que1.front());
            que1.pop();
        }
    }
    return result;
}

void merge_by_queue(vector<int> & vec)
{
    int size = vec.size();
    queue<queue<int > > result;
    for (int i = 0; i < size; i++)
    {
        queue<int> tmp;
        tmp.push(vec[i]);
        result.push(tmp);
    }

    while (result.size() != 1)
    {
        queue<int> tmp1 = result.front();
        result.pop();
        queue<int> tmp2 = result.front();
        result.pop();
        queue<int> tmp3 = Merge_queue(tmp1, tmp2);
        result.push(tmp3);
    }


    for (int i = 0; i < size; i++)
    {
        vec[i] = result.front().front();
        result.front().pop();
    }

}


int main()
{
    // // test Merge_queue
    // int size = 10;
    // queue<int> que1;
    // queue<int> que2;
    // for (int i = 0; i < size;  i++)
    // {
    //     if (i % 2)
    //         que1.push(i);
    //     else
    //         que2.push(i);
    // }
    // queue<int> result = Merge_queue(que1, que2);
    // for (int i = 0; i < size;  i++)
    // {
    //     cout << result.front() << " ";
    //     result.pop();
    // }
    // cout << endl;

    // vector<int> vec = produce(10);
    // merge_by_queue(vec);
    // print(vec);

    test_algorithm(merge_by_queue, "merge by queue", 1E4);
}