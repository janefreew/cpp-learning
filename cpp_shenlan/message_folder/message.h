#include<iostream>
#include<string>
#include<set>
#include "folder.h"

class Message
{
    friend class Folder;
private:
    /* data */
    std::string contents;
    std::set<Folder*> folders;
    void add_to_Folders(const Message &);
    void remove_from_Folders(const Message &);
public:
    //folders 被隐式初始化为空集合
    explicit Message(const std::string &str = ""):
        contents(str){}

    Message(const Message &);
    Message & operator=(const Message &);

    void save( Folder &);
    void remove( Folder &);
    
    Message(/* args */);
    ~Message();
};

Message::Message(/* args */)
{
}

Message::~Message()
{
}

void Message::save(Folder &f)
{
    folders.insert(&f);
    f.addMsg(this);

}

void Message::remove(Folder &f)
{
    folders.erase(&f);
    f.remMsg(this);
    
}
