#include "LinearProbingHashST.hpp"

int main()
{
    LinearProbingHashST<int , int> st;
    for (int i = 0; i < 1E4; i++)
        st.put(rand()%10, i);
    cout << st.contains(1) << endl;;
    // for (int i = 0; i < 1E4; i++)
    //     st.get(rand());
    // for (int i = 0; i < 1E6; i++)
        st.deleteKey(1);
    cout << st.contains(1) << endl;
}