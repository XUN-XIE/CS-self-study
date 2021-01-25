#include <deque>
#include <iostream>
using namespace std;

// cannot work
int main()
{
    srand(0);
    deque<int> que;
    int size = 5;
    for (int i = 0; i < size; i++)
        que.push_back( rand() % 100);

    int count = 0;
    while (count < size - 1)
    {
        count++;
        int val1 = que.front();
        que.pop_front();
        int val2 = que.front();
        que.pop_front();
        if (val1 < val2)
        {
            que.push_back(val1);
            que.push_back(val2);
        }
        else
        {
            que.push_back(val2);
            que.push_back(val1);
            count = 0;
        }
        
        cout << count << "  " << val1 << endl;
    }

    for (int i = 0; i < size; i++)
    {
        cout << que.front() << " ";
        que.pop_front();
    }
    cout << endl;
}