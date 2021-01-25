#include "INCLUDE.hpp"

class StrBlobPtr;
// class StrBlob;

class StrBlob
{
public:
    typedef vector<string>::size_type size_type;
    StrBlob();
    StrBlob(initializer_list<string> il);
    size_type size() const { return data->size(); }
    bool empty() const { return data->empty(); }
    void push_back(const string & t) { data->push_back(t); }
    void pop_back();
    string & front();
    string & back();

    StrBlobPtr begin() { return StrBlobPtr(*this); }
    StrBlobPtr end() { auto ret = StrBlobPtr(*this, data->size()); return ret; }

    const string & front() const;
    const string & back() const;

private:
    shared_ptr<vector<string>> data;
    void check(size_type i, const string & msg) const;
friend StrBlobPtr;
};

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