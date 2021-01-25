#include "Message.hpp"

void Message::save(Folder & f)
{
    folders.insert(&f);     // add the given Folder to our list of Folders
    f.addMsg(this);         // add this Message to f's set of Messages
}

void Message::remove(Folder & f)
{
    folders.erase(&f);      // take the given Folder out of our list of Folders
    f.remMsg(this);         // remove this Message to f's set of Messages
}

void Message::add_to_Folders(const Message & m)
{
    // for each Folder that holds m, add a pointer to this Message to taht Folder
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
    // handle self-assignment by removing pointers before inserting them
    remove_from_Folders();      // update existing Folders
    contents = rhs.contents;    // copy message contents from rhs
    folders = rhs.folders;      // copy Folder pointers from rhs
    add_to_Folders(rhs);        // add this Message to those Folders
    return *this;
}

void swap(Message & lhs, Message & rhs)
{
    using std::swap;    // not strictly needed in this case, but good habit
    // remove pointers to each Message from their (original) respective Folders
    for (auto f: lhs.folders)
        f->remMsg(&lhs);
    for (auto f: rhs.folders)
        f->remMsg(&rhs);
    // swap the contents and Folder pointer sets
    swap(lhs.folders, rhs.folders);
    swap(lhs.contents, rhs.contents);
    // add pointers to each Message from their (new) respective Folders
    for (auto f: lhs.folders)
        f->addMsg(&lhs);
    for (auto f: rhs.folders)
        f->addMsg(&rhs);
}

// void Message::move_Folders(Message * m)
// {
//     folders = std::move(m->folders);
//     for (auto f : folders)
//     {
//         f->remMsg(m);
//         f->addMsg(this);
//     }
//     m->folders.clear();
// }

// Message & Message::operator=(Message && rhs)
// {
//     if (this != rhs)
//     {
//         remove_from_Folders();
//         contents = std::move(rhs.contents);
//         move_Folders(&rhs);
//     }
//     return *this;
// }

int main()
{

}