#include "INCLUDE.hpp"

int main(int argc, char **argv)
{
    // 文件名也占用一个argv的空间！！！
    int a = stoi((string)argv[1]), b = stoi((string)argv[2]), c = stoi((string)argv[3]);
    if (a == b && b == c)
        cout << true << endl;
    else
        cout << false << endl;
}