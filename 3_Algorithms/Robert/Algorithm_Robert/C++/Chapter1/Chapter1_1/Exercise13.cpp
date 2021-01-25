#include "INCLUDE.hpp"

// learn how to apply built-in array in C++!!!! especially for combining with function
auto transposition(int arrays[][10], const int rows, const int cols) -> int (*) [20] {
    int (*transposed)[20] = new int[10][20];
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++)
            transposed[j][i] = *(*(arrays+i)+j);
    }
    return transposed;
}

int main() {
    int arrays[20][10];
    int rows = 20, cols = 10;

    int count = 0;
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            arrays[i][j] = count++;

    int (*transposed) [20] = transposition(arrays, 20, 10);
    for (int i = 0; i < cols; i++) {
        for (int j = 0; j < rows; j++) {
            cout <<  *(*(transposed+i)+j) << " ";
        }
        cout << endl;
    }
    delete [] transposed;
}
