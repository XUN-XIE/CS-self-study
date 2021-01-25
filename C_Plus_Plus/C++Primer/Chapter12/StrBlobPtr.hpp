#ifndef STRBLOBPTR_HPP
#define STRBLOBPTR_HPP

#include "INCLUDE.hpp"
// #include "StrBlob.cpp"

class StrBlob;


class StrBlobPtr
{
public:
    StrBlobPtr() : curr(0) { }
    StrBlobPtr(StrBlob & a, size_t sz = 0) : wptr(a.data), curr(sz) { }
    string & deref() const;
    StrBlobPtr & incr();

private:
    shared_ptr<vector<string>> check(size_t, const string &) const;

    weak_ptr<vector<string>> wptr;
    size_t curr;
};



#endif