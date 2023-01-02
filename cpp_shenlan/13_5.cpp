#include <string>
#include <iostream>
#include <memory>
#include <new>

using namespace std;
class HasPtr
{
private:
    /* data */
    std::string *ps;
    int i;
public:
    HasPtr(/* args */);
    // HasPtr(const std::string &s = std::string()):ps(new string(s)),i(0)
    HasPtr(const std::string &s):ps(new string(s)),i(0)
    {
        cout << " no default constructor is calling" << endl;

    }
    ~HasPtr();
};

HasPtr::HasPtr(/* args */)
{
    cout << "default constructor is calling" << endl;
}

HasPtr::~HasPtr()
{
    cout << "default deconstructor is calling" << endl;

}

int main()
{
    HasPtr m_hasptr1("s");
    HasPtr m_hasptr2();  //相当于函数声明
    HasPtr m_hasptr2;

    HasPtr *m_hasptr3 = new HasPtr("y");

    string s = std::string();
    cout << "ssssssss is " << s << endl;
    return 0;
}
