//
//  main.cpp
//  19Drill
//
//  Created by 谢逊 on 2020/1/23.
//  Copyright © 2020 谢逊. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>

using namespace std;

template <typename T>
class S
{
private:
    T val;
public:
    S(T a) : val{a} {}
    const T & get() const { return val; }
    T & get() { return val; }

    T & operator=(const T & arg) const { val = arg.val; }
};


int main()
{
    S<int> in(1);
    S<double> dou(1.1);
    S<char> ch('a');
    S<string> st("xiexun");
    S<vector<int>> vec({1,2,3,4,5});
    
    cout << in.get() << endl << dou.get() << endl << ch.get() << endl << st.get() << endl << vec.get()[3] << endl;
    
    
}

