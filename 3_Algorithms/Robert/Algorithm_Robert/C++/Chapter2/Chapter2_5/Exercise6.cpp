#include "../AllSort.hpp"

// 失败了，明明逻辑看起来一样，但是递归版本的实验结果有问题
int main()
{
    vector<int> vec;
    for (int i = 0; i < 10; i++)
        vec.push_back(rand() % 101);
    
    cout << select(vec, 0) << endl;
    print(vec);
}