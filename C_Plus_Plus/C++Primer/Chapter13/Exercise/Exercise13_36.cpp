#include "Exercise13_36.hpp"

void Message::save(Folder & f)
{
    folders.insert(&f);
    f.addMsg(this);
}

void Message::remove(Folder & f)
{
    folders.erase(&f);
    f.remMsg(this);
}

void Message::add_to_Folders(const Message & m)
{
    for (auto f : m.folders)
        f->addMsg(this);
}

Message::Message(const Message & m) : contents(m.contents), folders(m.folders)
{
    add_to_Folders(m);
}

void Message::remove_from_Folders()
{
    for (auto f : folders)
        f->remMsg(this);
}

Message::~Message()
{
    remove_from_Folders();
}

Message & Message::operator=(const Message & rhs)
{
    remove_from_Folders();
    contents = rhs.contents;
    folders = rhs.folders;
    // 为什么不用*this传入add_to_Folders
    add_to_Folders(rhs);
    return *this;
}

void swap(Message & lhs, Message & rhs)
{
    using std::swap;
    for (auto f: lhs.folders)
        f->remMsg(&lhs);
    for (auto f: rhs.folders)
        f->remMsg(&rhs);
    
    swap(lhs.folders, rhs.folders);
    swap(lhs.contents, rhs.contents);

    for (auto f: lhs.folders)
        f->addMsg(&lhs);
    for (auto f: rhs.folders)
        f->addMsg(&rhs);
}









void Folder::addMsg(Message * target)
{
    messages.insert(target);
}

void Folder::remMsg(Message * target)
{
    messages.erase(target);
}

int main()
{

}