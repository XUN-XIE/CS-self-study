#include "SeparateChainingHash.hpp"

int main()
{
    // cout << 0x7fffffff << endl;
    // cout << RAND_MAX << endl;
    // printf("%f\n", pow(2, 31));
    // // 相当于限制所有输入的数据，必须在 int 32位表示的最大值范围内！防止超出int的范围
    // cout << (134587698 & 0x7fffffff) << endl;

    SeparateChainingHash<int, int> st(997);
    for (int i = 0; i < 1E3; i++)
        st.put(rand()%10, i);
    // for (int i = 0; i < 1E4; i++)
    //     st.get(rand());
    cout << st.contains(3);
    st.deleteKey(3);
    cout << st.contains(3);

}