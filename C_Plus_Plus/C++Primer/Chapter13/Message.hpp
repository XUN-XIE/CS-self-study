#ifndef MESSAGE_HPP
#define MESSAGE_HPP
#include <string>
#include <set>

#include "Folder.hpp"

class Folder;

class Message
{
friend class Folder;
friend void swap(Message & lhs, Message & rhs);
public:
    // folders is implicitly initialized to the empty set
    explicit Message(const std::string &str = "") : contents(str) { }
    Message(const Message &);               // copy constructor
    Message & operator=(const Message &);   // copy assignment
    ~Message();                             // destructor

    // add / remove this Message from the specified Folder's set of messages
    void save(Folder &);
    void remove(Folder &);

    void move_Folders(Message *);
    Message(Message && m) : contents(std::move(m.contents)) { move_Folders(&m); }
    Message & operator=(Message && rhs);
private:
    std::string contents;           // actual message text
    std::set<Folder*> folders;      // Folders that have this Message

    // utility functions used by copy constructor, assignment and destructor
    // add this Message to the Folders that point to the parameter
    void add_to_Folders(const Message &);
    // remove this Message from every Folder in folders
    void remove_from_Folders();
};


#endif