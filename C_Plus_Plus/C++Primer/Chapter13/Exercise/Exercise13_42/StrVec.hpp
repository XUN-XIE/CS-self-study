#ifndef STRVEC_HPP
#define STRVEC_HPP

#include <iostream>
#include <string>
#include <memory>
#include <utility>
#include <initializer_list>

class StrVec
{
public:
    StrVec() : elements(nullptr), first_free(nullptr), cap(nullptr) { }
    StrVec(const StrVec &);
    StrVec & operator=(const StrVec &);
    ~StrVec();

    // Exercise 13.40
    StrVec(std::initializer_list<std::string *> );

    void push_back(const std::string &);
    size_t size() const { return first_free - elements; }
    size_t capacity() const { return cap - elements; }
    std::string *begin() const { return elements; }
    std::string *end() const { return first_free; }

private:
    std::allocator<std::string> alloc;

    void chk_n_alloc() { if (size() == capacity()) reallocate(); }
    std::pair<std::string *, std::string *> alloc_n_copy(const std::string *, const std::string *);
    void free();
    void reallocate();
    
    std::string * elements;
    std::string * first_free;
    std::string * cap;

};

#endif 