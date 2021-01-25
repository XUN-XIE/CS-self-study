#include "INCLUDE.hpp"

// 算法还有问题！！！

template<typename T>
vector<T> same_arr(vector<T> & vec1, vector<T> & vec2)
{
    auto iter1 = vec1.cbegin();
    auto iter2 = vec2.cbegin();

    vector<T> same_vec;

    auto big_iter = *iter1 > *iter2 ? iter1 : iter2;
    auto small_iter = *iter1 <= *iter2 ? iter1 : iter2;
    // 对比大小
    while (true) {
        bool found = false;
        while (small_iter != vec1.cend() && small_iter != vec2.cend() && *small_iter <= *big_iter)
        {
            if (found){
                small_iter++;
                continue;
            }

            if (*small_iter == *big_iter)
            {
                same_vec.push_back(*small_iter);
                found = true;
            }
            small_iter++;
        }
        auto tmp_iter = small_iter;
        small_iter = big_iter;
        big_iter = tmp_iter;

        cout << "---" << endl;

        if (big_iter == vec1.cend() - 1 || big_iter == vec2.cend() - 1) {
            cout << "---" << endl;
            while ( small_iter != vec1.cend() && small_iter != vec2.cend() )
            {
                if (*small_iter == *big_iter)
                {
                    same_vec.push_back(*small_iter);
                    break;
                }
                small_iter++;
            }
            break;
        }
    }

    return same_vec;
}


vector<int> getRandom(int size, int range_val)
{
    vector<int> vec;
    for(int i = 0; i < size; i++)
        vec.push_back(rand() % range_val);

    return vec;
}

int main()
{
    const int N = 10000;
    vector<int> vec1 = getRandom(10000, 1000);
    vector<int> vec2 = getRandom(10000, 1000);
    sort(vec1.begin(), vec1.end());
    sort(vec2.begin(), vec2.end());

    Timer timer;
    vector<int> same_vec = same_arr(vec1, vec2);
    double time_con = timer.elapsedTime();
    cout << time_con << endl;
}