#ifndef __FRACTION__
#define __FRACTION__

#include<iostream>
#include<cmath>
class Fraction {
public:
    Fraction(int num,int den = 1)
    : m_numerator(num), m_denominator(den) {}
    operator double() const {//转换函数，转为double类型
        return (double) m_numerator / m_denominator;
    }
private:
    int m_numerator;//分子
    int m_denominator;//分母
};

#endif