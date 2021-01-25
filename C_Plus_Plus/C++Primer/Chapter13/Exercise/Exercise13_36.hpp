#ifndef MESSAGE_HPP
#define MESSAGE_HPP
#include <string>
#include <set>

class Folder;

class Message
{
friend class Folder;
friend void swap(Message & lhs, Message & rhs);
public:
    explicit Message(const std::string &str = "") : contents(str) { }
    Message(const Message &);
    Message & operator=(const Message &);
    ~Message();

    void save(Folder &);
    void remove(Folder &);

private:
    std::string contents;
    std::set<Folder*> folders;
    void add_to_Folders(const Message &);
    void remove_from_Folders();
};


class Folder
{
public:
    void addMsg(Message *);
    void remMsg(Message *);
private:
    std::set<Message*> messages;
};

#endif