#include <iostream>

using namespace std;

struct Str
{
    /* data */
    int z;
    int x;
    int y;
};

int main(){

    // Str m_str{3,4};
    // cout << m_str.x << endl;

    Str m_str;
    m_str.y = 3;
    cout << m_str.z << endl;

}