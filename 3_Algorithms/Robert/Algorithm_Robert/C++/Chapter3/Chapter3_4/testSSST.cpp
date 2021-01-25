#include "SequentialSearchST.hpp"

int main()
{
    SequentialSearchST<int ,int> st;
    for (int i = 0; i < 1E4; i++)
        st.put(rand()%50, i);
    for (int i = 0; i < 1E4; i++)
        st.get(rand() % 50);
}