#ifndef INCLUDE_HPP
#define INCLUDE_HPP

#include <vector>
#include <string>
#include <list>
#include <deque>
#include <forward_list>
#include <map>
#include <set>
#include <algorithm>
#include <numeric>
#include <iterator>
#include <functional>

#include <stack>
#include <queue>



#include <iostream>
#include <fstream>
#include <sstream>

#include <memory>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

using std::begin;
using std::end;

using namespace std;

vector<string> read_data();
void print(vector<string> vec);
void print(vector<int> vec);
void print(vector<double> vec);
void print(deque<int> deq);
void print(forward_list<int> fl);



vector<string> read_data()
{
    vector<string> vec;
    string str;
    while(cin >> str)
        vec.push_back(str);
    
    return vec;
}

void print(vector<string> vec)
{
    for(auto i: vec)
        cout << i << " ";
    cout << endl;
}

void print(vector<int> vec)
{
    for(auto i: vec)
        cout << i << " ";
    cout << endl;
}

void print(vector<double> vec)
{
    for(auto i: vec)
        cout << i << " ";
    cout << endl;
}


void print(deque<int> deq)
{
    auto iter = deq.cbegin();
    while(iter != deq.cend())
        cout << *iter++ << " ";
    cout << endl;
}

void print(forward_list<int> fl)
{
    auto iter = fl.cbegin();
    while(iter != fl.cend())
        cout << *iter++ << " ";
    cout << endl;
}


/*

// LOG调试信息打印 from 开课吧


// 调试信息是为了帮助我们寻找bug，定位bug

// 为了能让LOG实现像printf的功能，需要变参宏！因为printf可以接受任意多的参数
// format 还是表示一个参数，真正实现多参数是  args...
// ## 的作用： 如果没有##，那么args不能是空的，就是必须有参数。
// 而如果加上##， 可以是空参数，作用是拼接内容
// 比如 a##b , 相当于 ab 直接拼接
// 所以  ##args 相当于 空拼接args， 所以这里参数可以为空！！！

// 注意，宏定义里加的 ; 是直接替换在待编译源码里的，不是用来表示C源码的语句的！！！

// 调试信息功能开关
// 方法一：标记方式 if 语句 实现调试信息开关！！！
int log_flag = 0;

// 方法二： 条件式编译， 实现代码剪裁！！！
// 注意这个方式的使用， 在命令行中输入 clang++ -DDEBUG 1log.cpp 进行编译
// 其中 -D 是定义宏定义的意思。因此 -DDEBUG 实际上定义了一个  DEBUG 的宏，所以可以打开LOG功能
// 注意 Vscode 情况下，运行目标文件是，运行 a.out 文件，不是 1log 文件
// 这个方法是最接近工程实践的用法，不习惯使用，可以调回去用自己喜欢的方法，比如使用 #if DEBUG == 1 这样的方式也可以！！！
#define DEBUG 1
#if DEBUG ==  1
#define LOG(format, args...) \
    if (log_flag == 0) {      \
        printf("[%s, %s, %d] ", __FILE__, __FUNCTION__,__LINE__); \
        printf(format, ##args); \
        printf("\n"); \
    }

// 不用 #endif， 因为如果裁剪了 LOG，C源代码丧失了LOG宏，会报错
// 其实可以考虑在LOG宏定义的内容处 使用 #endif
#else

#define LOG(format, arg...)

// 即使使用 #else 也别忘了加 #endif
#endif






// 测试框架 from 开课吧

// 实现定义颜色
// #color_code 表示字符串化！！！就是直接在color_code上加上双引号！！！
#define COLOR(msg, color_code) "\033[0;1;" #color_code "m" msg "\033[0m"

// 为什么可以三段字符串分开放
// 因为C++支持，不同的字符串直接放在一起，就可以拼接！！！
#define RED(msg) COLOR(msg, 31)
#define GREEN(msg) COLOR(msg, 32)
#define YELLOW(msg) COLOR(msg, 33)
#define BLUE(msg) COLOR(msg, 34)


// 宏定义实现 EXPECT

// 这里必须加最外侧的{} 否则__typeof(a) 会重定义 __a, __b。
// 这里的 __typeof() 的使用是为了减少bug，使 __a, __b 类型一致
#define EXPECT(a, comp, b)  {\
    __typeof(a) __a = (a), __b = (b); \
    if ( ! ( (__a) comp (__b) ) ) {   \
        printf(RED("\t%s:%d: Failure\n"), __FILE__, __LINE__); \
        printf(RED("\t\tExpected: (%s) %s (%s), actual: %d vs %d\n"), #a, #comp, #b, __a, __b); \
    } \
}

#define EXPECT_EQ(a,b) EXPECT(a, ==, b)
#define EXPECT_NE(a,b) EXPECT(a, !=, b)
#define EXPECT_LT(a,b) EXPECT(a, <, b)
#define EXPECT_LE(a,b) EXPECT(a, <=, b)
#define EXPECT_GT(a,b) EXPECT(a, >, b)
#define EXPECT_GE(a,b) EXPECT(a, >=, b)

int add(int, int);
int RUN_ALL_TEST();

// 初步框架
struct FUNC {
    // 返回类型为 void 应该是因为我们只需要打印，不需要返回
    // 参数为空，也是同理
    void (*func)();
    const char * func_name;
};
FUNC func_arr[100];

int func_cnt = 0;


#define TEST(a, b) \
void a##_##b();    \
__attribute__((constructor))    \
void reg_##a##_##b() {  \
    add_func(a##_##b, #a "." #b);    \
    return ;    \
}   \
void a##_##b()

void add_func(void (*func)(), const char *str) {
    func_arr[func_cnt].func = func;
    func_arr[func_cnt].func_name = str;
    func_cnt += 1;
}

int RUNALL_ALL_TEST() {
    for (int i = 0; i < func_cnt; i++){
        printf(GREEN("[   RUN   ") " %s\n", func_arr[i].func_name);
        func_arr[i].func();
    }

    return 0;
}

*/

#endif