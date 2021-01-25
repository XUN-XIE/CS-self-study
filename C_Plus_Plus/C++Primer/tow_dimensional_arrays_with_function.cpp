/*
used for learning tow dimensional array combined with function.
*/

#include<iostream>
#include<string>
#include<vector>
#include<set>
#include <cstdlib>
#include <cstddef>
#include <list>
#include <functional>
#include <unordered_map>
#include <algorithm>
#include <iterator>
#include <ostream>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::list;
using std::unordered_map;


template <typename T,unsigned N,unsigned M>
T (*trans(T (&mat)[M][N]))[N]
{
	T(*p)[N] = new T[M][N];
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			p[j][i] =mat[i][j];
	return p;
	
}
int main()
{
	int a[2][4] = {1,2,3,4,5,6,7,8};
	int(*p)[4];
	p = trans(a);
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 2; j++)
			cout << p[i][j] <<" " ;
		cout << endl;
	}
	
	
	delete[]p;
	
	system("pause");
	return 0;
}