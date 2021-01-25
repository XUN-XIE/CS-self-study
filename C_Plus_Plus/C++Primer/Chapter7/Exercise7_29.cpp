#ifndef SCREEN_HPP
#define SCREEN_HPP

#include "INCLUDE.hpp"

class Screen
{
public:
    typedef string::size_type pos;

    Screen() = default;
// Pay attention to the initialization for "contents" which just like initialize a "string" type!!!!
    Screen(pos ht, pos wd, char c) : height(ht), width(wd), contents(ht * wd, c) {}

    char get() const { return contents[cursor]; }
    inline char get(pos ht, pos wd) const;
    Screen move(pos r, pos c);

    void some_member() const;

    Screen  set(char);
    Screen & set(pos, pos, char);

    Screen display(ostream & os) const { do_display(os); return *this; }

private:
    pos cursor = 0;
    pos height = 0, width = 0;
    string contents;

    mutable size_t access_ctr;

    void do_display(ostream & os) const { os << contents; }
};

// as conventions, inline functions should be included in header file
inline
Screen Screen::move(pos r, pos c)
{
    pos row = r * width;
    cursor = row + c;
    return *this;
}

char Screen::get(pos r, pos c) const
{
    pos row = r * width;
    return contents[row + c];
}

void Screen::some_member() const
{
// keep a count of the calls to any member function whatever other work this member needs to do
    ++access_ctr;
}

inline
Screen Screen::set(char c)
{
    contents[cursor] = c;
    return *this;
}

Screen & Screen::set(pos r, pos col, char ch)
{
    contents[ r * width + col ] = ch;
    return *this;
}

int main()
{
    Screen myScreen(5, 5, 'X');
    myScreen.move(4,0).set('#').display(cout);
    cout << "\n";
    myScreen.display(cout);
    cout << endl;
}



#endif