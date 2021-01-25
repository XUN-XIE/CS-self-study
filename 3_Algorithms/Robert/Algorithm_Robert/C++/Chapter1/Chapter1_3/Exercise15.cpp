#include "INCLUDE.hpp"

// 使用 pass by copy 防止对原对象的修改
template<typename T>
void print_k_to_last(queue<T> target, int k);

int main(int argc, char * argv[])
{
    queue<string> target;
    target.push("xie");
    target.push("xun");
    target.push("xiao");
    target.push("wan");

    print_k_to_last(target, stoi(argv[1]));
}

template<typename T>
void print_k_to_last(queue<T> target, int k)
{
    int count = 0;
    int total = target.size();
    while (!target.empty())
    {
        if (count < total - k)
            target.pop();
        else
        {
            cout << target.front() << " ";
            target.pop();
        }
        count++;
    }
    cout << endl;
}