#include "INCLUDE.hpp"

vector<int> * allocate_vec();
vector<int> * read_vec(vector<int> *);
void print_vec(vector<int> *);

int main()
{
    vector<int> * ptr = allocate_vec();
    ptr = read_vec(ptr);
    print_vec(ptr);

}

vector<int> * allocate_vec()
{
    vector<int> * ptr = new vector<int>;
    return ptr;
}

vector<int> * read_vec(vector<int> * ptr)
{
    int num;
    while(cin >> num)
        ptr->push_back(num);
    return ptr;
}
void print_vec(vector<int> * ptr)
{
    auto iter = ptr->begin();
    while(iter != ptr->end())
        cout << *iter++ << "\t";
    cout <<endl;
    delete ptr;
    ptr = nullptr;
}