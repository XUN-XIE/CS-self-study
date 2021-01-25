#include "INCLUDE.hpp"

int main() {
    queue<int> target;
    
    int order = 3;
    for(int i = 0; i < 15; i++)
        target.push(i);
    
    int count = 1;
    while (target.size() != 1) {
        if (count % order == 0)
                target.pop();
            else
            {
                int tmp = target.front();
                target.pop();
                target.push(tmp);
                cout << tmp << "\t";
            }
            count++;
            cout << endl;
    }
    cout << target.front() << endl;

    return 0;
}