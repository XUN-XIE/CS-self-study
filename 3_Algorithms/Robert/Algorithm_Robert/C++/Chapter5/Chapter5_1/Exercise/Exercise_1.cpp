#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <fstream>

using namespace std;

map<char, int> getRadix(vector<string> & vec)
{
    map<char, int> Radix;
    for (int i = 0; i < vec.size(); i++)
    {
        int len = vec[i].length();
        for (int j = 0; j < len; j++)
            Radix[vec[i][j]] += 1;
    }

    int order = 0;
    for ( auto & ele : Radix )
        ele.second = order++;
    return Radix;
}


void RadixSort(vector<string> & stringVec)
{
    map<char, int> Radix = getRadix( stringVec );
    size_t R = Radix.size();

    /* // debug use
    for ( auto ele: Radix )
    {
        cout << ele.first << " " << ele.second << endl;
    }
    */
    

    size_t N = stringVec.size();
    vector<string> aux(N);

    size_t length = stringVec[0].length();
    for (int d = length - 1; d >= 0; d--)
    {
        
        // Sort by key-indexed counting on dth char

        // Compute frequency counts. 
        vector<int> count(R+1);
        for (size_t i = 0; i < N; i++)
            count[ Radix[ stringVec[ i ][ d ] ] + 1 ]++;

        // Transform counts to indices.
        for (size_t r = 0; r < R; r++)
            count[ r + 1 ] += count[ r ];

        // Distribute.
        for (size_t i = 0; i < N; i++)
            aux[ count[ Radix[ stringVec[ i ][ d ] ] ]++ ] = std::move(stringVec[i]);

        // Copy back.
        for (size_t i = 0; i < N; i++)
            stringVec[ i ] = std::move(aux[ i ]);
    }
}

vector<string>
readIn()
{
    ifstream infile;
    infile.open("/Users/xiexun/Desktop/Algorithm_Robert/C++/Chapter5/Chapter5_1/words3.txt");

    vector<string> StringVec;
    string word;
    while (infile >> word)
        StringVec.push_back(word);
    return StringVec;
}

void print(vector<string> & vec)
{
    for (int i = 0; i < vec.size(); i++)
        cout << vec[i] << " ";
    cout << endl;
}

int main()
{
    vector<string> vec = readIn();
    RadixSort(vec);
    print( vec );
}