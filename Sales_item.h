#ifndef SALESITEM_H//如果未定义SALESITEM_H
#define SALESITEM_H//则定义SALESITEM_H
// Definition of Sales_item class and related functions goes here


#include <iostream>
#include <string>
class Sales_item {
	//friend为友元声明，允许一个函数被其它类访问，即使是private类型的，也可以进行访问
	//形象的说就是把家里的钥匙给了别人，让别人也可以进去
	//bool 声明为布尔类型
	//operator操作符重载


	friend bool operator==(const Sales_item&, const Sales_item&);
	// other members as before
public:
	// added constructors to initialize from a string or an istream
	Sales_item(const std::string& book) :
		isbn(book), units_sold(0), revenue(0.0) { }
	Sales_item(std::istream& is) { is >> *this; }
	friend std::istream& operator>>(std::istream&, Sales_item&);
	friend std::ostream& operator<<(std::ostream&, const Sales_item&);
public:
	// operations on Sales_item objects
	// member binary operator: left-hand operand bound to implicit this pointer
	Sales_item& operator+=(const Sales_item&);
	// other members as before

public:
	// operations on Sales_item objects
	double avg_price() const;
	bool same_isbn(const Sales_item& rhs) const
	{
		return isbn == rhs.isbn;
	}
	// default constructor needed to initialize members of built-in type
	Sales_item() : units_sold(0), revenue(0.0) { }
	// private members as before
public:
	std::string isbn;//ISBN编号
	unsigned units_sold;//销量
	double revenue;//销售价格
};
// nonmember binary operator: must declare a parameter for each operand
Sales_item operator+(const Sales_item&, const Sales_item&);
inline bool
operator==(const Sales_item& lhs, const Sales_item& rhs)
{
	// must be made a friend of Sales_item
	return lhs.units_sold == rhs.units_sold &&
		lhs.revenue == rhs.revenue &&
		lhs.same_isbn(rhs);
}
inline bool
operator!=(const Sales_item& lhs, const Sales_item& rhs)
{
	return !(lhs == rhs); // != defined in terms of operator==
}
using std::istream; using std::ostream;
// assumes that both objects refer to the same isbn
inline
Sales_item& Sales_item::operator+=(const Sales_item& rhs)
{
	units_sold += rhs.units_sold;
	revenue += rhs.revenue;
	return *this;
}
// assumes that both objects refer to the same isbn
inline
Sales_item
operator+(const Sales_item& lhs, const Sales_item& rhs)
{
	Sales_item ret(lhs); // copy lhs into a local object that we'll return，这是一个临时对象
	ret += rhs;           // 这里调用了重载之后的+=操作符，将rhs的成员值加到ret的成员值上
	return ret;           // return ret by value
}

//输入符号重载，需要输入isbn编号、销量以及销售价格
inline
istream&
operator>>(istream& in, Sales_item& s)
{
	double price;
	in >> s.isbn >> s.units_sold >> price;
	// check that the inputs succeeded
	if (in)
		s.revenue = s.units_sold * price;
	else
		s = Sales_item(); // input failed: reset object to default state
	return in;
}

//输出符号重载，需要输出isbn编号、销量、总销售额以及平均价格
inline
ostream&
operator<<(ostream& out, const Sales_item& s)
{
	out << s.isbn << "\t" << s.units_sold << "\t"
		<< s.revenue << "\t" << s.avg_price();
	return out;
}

inline     //内联，相当于宏的展开，不需要进行参数压栈，代码生成的一系列操作
double Sales_item::avg_price() const
{
	if (units_sold)
		return revenue / units_sold;
	else
		return 0;
}
#endif
