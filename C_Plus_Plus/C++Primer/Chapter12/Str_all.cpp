#include "Str_all.hpp"

StrBlob::StrBlob() : data(make_shared<vector<string>>()) { }
StrBlob::StrBlob(initializer_list<string> il) : data(make_shared<vector<string>>(il)) { }

void StrBlob::check (size_type i, const string & msg) const
{
    if (i >= data->size())
        throw out_of_range(msg);
}

string & StrBlob::front()
{
    check(0, "front on empty StrBlob");
    return data->front();
}

string & StrBlob::back()
{
    check(0, "back on empty StrBlob");
    return data->back();
}

void StrBlob::pop_back()
{
    check(0, "pop back on empty StrBlob");
    data->pop_back();
}

const string & StrBlob::front() const
{
    check(0, "front on empty StrBlob");
    return data->front();
}

const string & StrBlob::back() const
{
    check(0, "back on empty StrBlob");
    return data->back();
}


int main()
{}

shared_ptr<vector<string>> StrBlobPtr::check(size_t i, const string & msg) const
{
    auto ret = wptr.lock();
    if (!ret)
        throw runtime_error("unbound StrBlobPtr");
    if (i >= ret->size())
        throw out_of_range(msg);
    
    return ret;
}

string & StrBlobPtr::deref() const
{
    auto p = check(curr, "dereference past end");
    return (*p)[curr];
}

StrBlobPtr & StrBlobPtr::incr()
{
    check(curr, "increment past end of StrBlobPtr");
    ++curr;
    return *this;
}

