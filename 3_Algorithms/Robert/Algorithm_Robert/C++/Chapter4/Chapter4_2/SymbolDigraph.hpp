#include "Digraph.hpp"

class SymbolDigraph
{
private:
    map<string, int> st;
    string * keys;
    Digraph G;

public:
    SymbolDigraph(string stream, string sp)
    {
        ifstream infile;
        infile.open(stream);
        string tmp;

        // int count = 0;
        while (getline(infile, tmp))
        {
            int first = tmp.find(sp, 0);
            string root = tmp.substr(0, first);
            // if (count < 3)
            //     cout << root << "!!!" << endl;
            // count++;
            int next_pos = first;
            st.insert(pair<string, int>(root, st.size()));
            string child;
            while (next_pos < tmp.length())
            {
                int cur = next_pos + 1;
                next_pos = tmp.find(sp, cur);
                child = tmp.substr(cur, next_pos - cur);
                st.insert(pair<string, int>(child, st.size()));
            }
        }
        infile.close();

        keys = new string[st.size()];
        for (auto target : st)
        {
            string name = target.first;
            keys[st[name]] = name;
        }

        G = Digraph(st.size());
        infile.open(stream);
        while (getline(infile, tmp))
        {
            int first = tmp.find(sp, 0);
            string root = tmp.substr(0, first);
            int v = st[root];
            int next_pos = first;
            string child;
            while (next_pos < tmp.length())
            {
                int cur = next_pos + 1;
                next_pos = tmp.find(sp, cur);
                child = tmp.substr(cur, next_pos - cur);
                G.addEdge(v, st[child]);
            }
        }
        infile.close();
    }

    ~SymbolDigraph()  {   delete [] keys; }

    bool contains(string s) {   return st.find(s) != st.end(); }

    int index(string s)     {   return st.at(s);   }

    string name(int v)      {   return keys[v];  }

    Digraph get_graph()     {   return G;   }
};