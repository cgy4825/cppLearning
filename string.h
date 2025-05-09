#ifndef __MYSTRING__
#define __MYSTRING__

#include <string.h>
#include<iostream>
using namespace std;
class String
{
public:
    String (const char* cstr = 0);
    String (const String& str);//拷贝构造函数
    String& operator= (const String& str);//拷贝赋值运算符
    ~String();//析构函数，释放内存：该类死亡的时候该函数自动调用
    char* get_c_str() const {return m_data;}

private:
    char* m_data;
};

inline
String::String (const char* cstr = 0){
    if(cstr){
        m_data = new char[strlen(cstr)+1];
        strcpy(m_data,cstr);
    }else{//未指定初始值
        m_data = new char[1];
        *m_data = '\0';
    }
}
inline
String::~String()
{
    delete[] m_data;
}
//两个指针不一样，但是里面存储的内容是一样的
inline
String::String(const String& str){
    m_data = new char[strlen(str.m_data) + 1];
    strcpy(m_data,str.m_data);
}
//拷贝赋值函数
inline
String& String::operator= (const String& str){
    if(this == &str){
        //如果是自己赋值，则什么都不做,这一步很重要
        //主要是考虑两个指针指向同一个地方的情况，如果直接delete，后面就会空指针异常
        return *this;
    }
    delete[] m_data;
    m_data = new char[strlen(str.m_data) + 1];
    strcpy(m_data,str.m_data);
    return *this;
}
ostream& operator<< (ostream& os,const String& str){
    os << str.get_c_str();
    return os;
}
#endif