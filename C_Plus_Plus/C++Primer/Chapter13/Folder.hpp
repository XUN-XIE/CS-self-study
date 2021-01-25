#ifndef FOLDER_HPP
#define FOLDER_HPP
#include <string>
#include <set>

class Message;

class Folder
{
friend class Message;
friend void swap(Folder & lhs, Folder & rhs);
public:
    void addMsg(Message *);
    void remMsg(Message *);

private:
    std::string name;
    std::set<Message*> messages;

};

void Folder::addMsg(Message * msg)
{
    messages.insert(msg);
}

void Folder::remMsg(Message * msg)
{
    messages.erase(msg);
}

#endif