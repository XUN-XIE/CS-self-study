#include "TextQuery.hpp"

string make_plural(size_t ctr, const string & word, const string & ending)
{
    return (ctr > 1) ? word + ending : word;
}

TextQuery::TextQuery(ifstream & is) : file(new vector<string>)
{
    string text;
    while (getline(is, text))
    {
        file->push_back(text);
        int n = file->size() - 1;
        istringstream line(text);
        string word;
        while (line >> word)
        {
            auto & lines = wm[word];
        // 如果word是第一次遇见，需要給新的set<line_no>分配内存，所以使用new！！！
            if (!lines)
                lines.reset(new set<line_no>);
        // 如果word重复遇见，则直接在该set上添加元素
            lines->insert(n);
        }
    }
}

QueryResult TextQuery::query(const string & sought) const
{
    // why is this applying static??? Maybe it can reduce the dynamical memory constructed by the no-found word
    static shared_ptr<set<line_no > > nodata(new set<line_no>);

    auto loc = wm.find(sought);
    if (loc == wm.end())
        return QueryResult(sought, nodata, file);
    else
        return QueryResult(sought, loc->second, file);
}

ostream & print(ostream & os, const QueryResult & qr)
{
    os << qr.sought << " occurs " << qr.lines->size() << " " << make_plural(qr.lines->size(), "time", "s") << endl;

    for (auto num : *qr.lines)
        os << "\t(line " << num + 1 << ") " << *(qr.file->begin() + num) << endl;
    
    return os;
}

void runQueries(ifstream & infile)
{
    TextQuery tq(infile);
    while (true)
    {
        cout << "enter word to lock for, or q to quit: ";
        string s;

        if (!(cin >> s) || s == "q")
            break;
        print(cout, tq.query(s)) << endl;
    }
}

int main()
{
    ifstream infile("infile.txt");
    runQueries(infile);
}