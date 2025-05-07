#ifndef __COMPLEX__
#define __COMPLEX__
//复数头文件
#include<cmath>
#include<iostream>
class ostream;

class complex;
complex&
__doapl(complex* ths,const complex& r);

class complex
{
public:
//函数部分
    complex(double r=0,double i=0)//构造函数，有默认参数
    : re(r),im(i) //初始化参数
    {}

    complex& operator += (const complex&);
    double real () const {return re;}//返回实部，只是取数据，不会改变数据内容，加上const
    double imag () const {return im;}//返回虚部
private:
    double re, im;//所有的数据都应该是私有的
    
    //友元函数
    friend complex& __doapl(complex* ,const complex& );
};

inline double
imag(const complex& x){
    return x.imag();
}

inline double
real(const complex& x){
    return x.real();
}

ostream& operator << (ostream& os,const complex& x){
    return os << '(' << x.real() << ',' << x.imag() << ')' ;
};
inline complex&
__doapl(complex* ths,const complex& r){
    ths->re += r.re;
    ths->im += r.im;
    return *ths;//这里是返回对象，但是接收端是reference
    //使用return by reference既使用&，传递者无需知道接收者是以reference还是value传递
}

//任何一个成员函数都隐含一个this指针，因此可以直接使用this指针访问成员变量
//操作符的重载
inline complex&
complex::operator +=(const complex& r){//隐藏一个参数this,但是不能写出来
    return __doapl(this,r);
}

//操作符重载，对于非成员函数，无this指针，因此需要使用全局函数
//这些函数绝对不可以return by reference,因为它们的返回值必定是个local object
//复数加复数
inline complex
operator + (const complex& x,const complex& y){
    return complex(real(x) + real(y),imag(x) + imag(y));
    //临时对象，typename();
}
//复数加实数
inline complex
operator + (const complex& x,double y){
    return complex(real(x) + y,imag(x));
}
//实数加复数
inline complex
operator + (double x,const complex& y){
    return complex(x + real(y),imag(y));
}

//正号
inline complex
operator + (const complex& x){
    return x;
}

//负号,取反
inline complex
operator - (const complex& x){
    return complex(-real(x),-imag(x));//临时对象绝对不可以return by reference
}

//等不等于
inline bool
operator == (const complex& x,const complex& y){
    return real(x) == real(y) && imag(x) == imag(y);
}

inline bool
operator == (const complex& x,double y){
    return real(x) == y && imag(x) == 0;
}

inline bool
operator == (double x,const complex& y){
    return real(y) == x && imag(y) == 0;
}

//共轭复数，实部相同，虚部相反
inline complex
conj (const complex& x){
    return complex(real(x),-imag(x));
}

ostream&
operator << (ostream& os,const complex& x){
    return os << '(' << real(x) << ',' << imag(x) << ')' ;
}






#endif