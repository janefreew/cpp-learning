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

    // HasPtr(/* args */);
    // 可选参数
    HasPtr(const std::string &s = std::string()):ps(new string(s)),i(0)
    {
        cout << " no default constructor is calling" << endl;

    }
    //copy constructor
    HasPtr(HasPtr &P):ps(new string(*P.ps)),i(P.i){}
    //copy assignment
    HasPtr& operator=(const HasPtr&);
    string& get_ps()
    {
        return *this->ps;
    }
    ~HasPtr();
};

HasPtr::~HasPtr()
{
    cout << "default deconstructor is calling" << endl;

}

HasPtr& HasPtr::operator=(const HasPtr& rhs) 
{
    //step1 拷贝底层 string
    auto newp = new string(*rhs.ps);
    //step2 释放旧内存
    delete ps;
    //step3 从右侧运算对象拷贝数据到本对象
    ps = newp;
    i = rhs.i;
    
    //step4 返回本对象
    return *this;
}

int main()
{
    HasPtr m_hasptr1("s");
    // HasPtr m_hasptr2();  //相当于函数声明
    HasPtr m_hasptr2 = m_hasptr1;

    HasPtr *m_hasptr3 = new HasPtr("y");

    string s = std::string();
    cout << "m_hasptr2.get_ps() is " << m_hasptr2.get_ps() << endl;
    return 0;
}
