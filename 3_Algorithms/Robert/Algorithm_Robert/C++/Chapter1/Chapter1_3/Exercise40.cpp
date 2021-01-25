#include "INCLUDE.hpp"

int main()
{
    // stringstream is("xun xie xie wan");
    string word;
    queue<string> sequence;
    while(cin >> word) {
        if (sequence.empty())
        {
            sequence.push(word);
            continue;
        }
        
        queue<string> cache;

        // 遍历查找是否重复
        while (sequence.size() > 0) {
            string front_s = sequence.front();
            if (front_s != word)
                cache.push(front_s);
            sequence.pop();
        }
        sequence.push(word);

        // 复原sequence
        while (cache.size() > 0)
        {
            string tmp = cache.front();
            sequence.push(tmp);
            cache.pop();
        }
    }

    cout << "------" << endl;

    while (sequence.size() > 0)
    {
        string tmp = sequence.front();
        sequence.pop();
    
        cout << tmp << "\t";
    }
    cout << endl;

}
