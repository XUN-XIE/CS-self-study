#include "INCLUDE.hpp"

shared_ptr<vector<int>> allocate_vec();
shared_ptr<vector<int>> read_vec(shared_ptr<vector<int>>);
void print_vec(shared_ptr<vector<int>>);

int main()
{
    shared_ptr<vector<int>> ptr = allocate_vec();
    cout << ptr.use_count() << endl;
    ptr = read_vec(ptr);
    print_vec(ptr);
}

shared_ptr<vector<int>> allocate_vec()
{
    shared_ptr<vector<int>> ptr = make_shared<vector<int>>();
    return ptr;
}

shared_ptr<vector<int>> read_vec(shared_ptr<vector<int>> ptr)
{
    int num;
    while (cin >> num)
        ptr->push_back(num);
    return ptr;
}

void print_vec(shared_ptr<vector<int>> ptr)
{
    auto iter = ptr->begin();
    while(iter != ptr->end())
        cout << *iter++ << "\t";
    cout <<endl;
}