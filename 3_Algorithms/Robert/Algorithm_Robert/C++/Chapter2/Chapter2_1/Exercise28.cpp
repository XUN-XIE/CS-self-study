#include "../AllSort.hpp"


// 运行前，在AllSort.hpp 将 produce 函数的生成最大数值修改为2即可
int main()
{
    for (int i = 128; i < 128 * pow(2,8) + 1; i *= 2)
    {
        test_algorithm(InsertionSort, "Insertion", i);
        test_algorithm(SelectionSort, "Selection", i);
    }
}