//
//  tempmemb.hpp
//  14.20
//
//  Created by 谢逊 on 2020/1/21.
//  Copyright © 2020 谢逊. All rights reserved.
//

#ifndef tempmemb_hpp
#define tempmemb_hpp

#include <iostream>
using namespace std;

template<typename T>
class beta
{
private:
    template < typename V >
    class hold
    {
    private:
        V val;
    public:
        hold(V v = 0) : val(v) {}
        void show() const { cout << val << endl; }
        V Value() const {return val;}
    };
    
    hold<T> q;
    hold<int> n;
public:
    beta (T t, int i) : q(t), n(i) {}
    template <typename U>
    U blab(U u, T t) { return (n.Value() + q.Value()) * u / t; }
    void Show() const { q.show(); n.show(); }
};

#endif /* tempmemb_hpp */
