#include <iostream>

using namespace std;

// MSD
// N
// 假设 第 d 轮
// count[0] = 0
// count[1] = d
// count[2] = N
// 从这题看， 好像MSD 会对 count[1] 已经排序过的部分，做很多不必要的操作
// 但是 每次的 low 都把排序过的部分 屏蔽掉了，所以不会存在这些额外开销


// quick-3-way
// 2 
// 两次递归调用，low, high, lt, gt 都没有变化
// 并且第二次递归调用时， v = -1， 所以三个递归调用，都是直接返回的！