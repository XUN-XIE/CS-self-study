#ifndef TEXTQUERY_HPP
#define TEXTQUERY_HPP

#include "INCLUDE.hpp"

class QueryResult;

// 使用内存管理的原因，每次query的word，如果动态管理内存了，那么查询后会自动释放内存
// 如果不动态管理内存，那么查询很多词后，内存会一直被增长势占用

// 设计思想，个人理解，定义QueryResult的原因，部分是因为C++函数返回知能是一个对象，所以使用class type保存返回更多的信息！
class TextQuery
{
public:
    using line_no = vector<string>::size_type;
    TextQuery(ifstream & );
    QueryResult query(const string &) const;
private:
// record the texts has read in file
    shared_ptr<vector<string>> file;

    // record the lines that word has appeared
    map<string, shared_ptr<set<line_no> > > wm;
};


class QueryResult 
{
friend  ostream & print(ostream &, const QueryResult &);

public:
// pay atttention to reference of line_no defined in TextQuery
    QueryResult(string s, shared_ptr<set<TextQuery::line_no > > p, shared_ptr<vector<string > > f) : sought(s), lines(p), file(f) { }

private:
    string sought;
    shared_ptr<set<TextQuery::line_no > > lines;
    shared_ptr<vector<string > > file; 

};

#endif