//
//  main.cpp
//  Chapter20
//
//  Created by 谢逊 on 2020/1/23.
//  Copyright © 2020 谢逊. All rights reserved.
//

#include <iostream>

using namespace std;

template <typename Elem>
class list{
public:
    class iterator;
    
    iterator begin();
    iterator end();
    
    iterator insert(iterator p, const Elem & v);
    iterator erase(iterator p);
    
    void push_back(const Elem & v);
    void push_front(const Elem & v);
    void pop_front();
    void pop_back();
    
    Elem & front();
    Elem & back();
};

template <typename Elem>
class list::iterator{
    Link<Elem> * curr;
public:
    iterator(Link<Elem> * p) : curr{p} {}
    
    iterator & operator++() { curr = curr->succ; return *this; }
    iterator & operator--() { curr = curr->prev; return *this; }
    Elem & operator*() { return curr->val; }
    
    bool operator==(const iterator & b) const { return curr == b.curr; }
    bool operator!=(const iterator & b) const { return curr != b.curr; }
    };
