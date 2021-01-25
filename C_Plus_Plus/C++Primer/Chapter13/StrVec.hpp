#ifndef STRVEC_HPP
#define STRVEC_HPP

#include <iostream>
#include <string>
#include <memory>
#include <map>
#include <utility>
#include <initializer_list>

class StrVec
{
public:
    StrVec() : elements(nullptr), first_free(nullptr), cap(nullptr) { }
    StrVec(const StrVec &);
    StrVec & operator=(const StrVec &);
    ~StrVec();
    void push_back(const std::string &);
    size_t size() const { return first_free - elements; }
    size_t capacity() const { return cap - elements; }
    std::string *begin() const { return elements; }
    std::string *end() const { return first_free; }

    // Exercise 13.40
    StrVec(std::initializer_list<std::string *> );

    // move constructor
    StrVec(StrVec && s) noexcept;
    // move assignment
    StrVec & operator=(StrVec && rhs);

    // move version
    void push_back(std::string &&);
private:
    // allocates the elements used by the functions that add elements taht add elements to the StrVec
    std::allocator<std::string> alloc;
    void chk_n_alloc() { if (size() == capacity()) reallocate(); }
    // utilities used by the copy constructor, assignment operator, and destructor
    std::pair<std::string *, std::string *> alloc_n_copy(const std::string *, const std::string *);
    void free();        // destroy the elements and free the space
    void reallocate();  // get more space and copy the existing elements
    
    std::string * elements;     // pointer to the first element in the array
    std::string * first_free;   // pointer to the first free element in the array
    std::string * cap;          // pointer to one past the end of the array

};

#endif 