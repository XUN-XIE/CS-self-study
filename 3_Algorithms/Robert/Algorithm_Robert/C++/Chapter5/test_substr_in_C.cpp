#include <bits/stdc++.h>
using namespace std;

// 结果可知，C++ 中的 substr 操作，是 O(N) 时间复杂度！
// 如果想要 substr 操作为 O(1)，必须自己设计实现新的 string 类
int main()
{
    string test(10000000, 'c');
    
    for (int N = 1000; N < 1E7; N *= 10)
    {
        double start = clock();
        for (int i = 0; i < 1E5; i++)
            test.substr(100, N);
        double endtime = clock();
        cout << (endtime - start ) / CLOCKS_PER_SEC << endl;
    }
}
