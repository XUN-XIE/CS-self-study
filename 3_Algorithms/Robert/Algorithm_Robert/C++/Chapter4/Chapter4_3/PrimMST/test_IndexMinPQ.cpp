#include "IndexMinPQ.hpp"

int main()
{
    vector<string> strings = { "it", "was", "the", "best", "of", "times", "it", "was", "the", "worst" };
    IndexMinPQ<string> pq(strings.size());
    for (int i = 0; i < strings.size(); i++) {
            pq.insert(i, strings[i]);
    }

    // delete and print each key
    while (!pq.isEmpty()) {
        int i = pq.delMin();
        cout << i << " " << strings[i] << endl;
    }
    cout << endl;

    // reinsert the same strings
    for (int i = 0; i < strings.size(); i++) {
        pq.insert(i, strings[i]);
    }

    while (!pq.isEmpty()) {
            pq.delMin();
    }
}