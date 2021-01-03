// Single-line comment
/*
 * Multiple line comment
 */

#include <iostream>
#include "overloading_integer.h"

using namespace std;

Integer::Integer()
{
	cout << "Integer()" << endl;
	ptr_value = new int{0};
}

Integer::Integer(int value)
{
	cout << "Integer(int)" << endl;
	ptr_value = new int{value};
}

Integer::Integer(Integer const &obj)
{
	cout << "Integer(Integer const &)" << endl;
	ptr_value = new int{*obj.ptr_value};
}

Integer::Integer(Integer && obj)
{
	cout << "Integer(Integer &&)" << endl;
	ptr_value = obj.ptr_value;
	obj.ptr_value = nullptr;
}

int Integer::get_value() const
{
	cout << "int get_value()" << endl;
	return *ptr_value;
}

void Integer::set_value(int value)
{
	cout << "void set_value(int)" << endl;
	if(ptr_value == nullptr)
	{
		ptr_value = new int{value};
	}
	else
	{
		*ptr_value = value;
	}
}

Integer::~Integer()
{
	cout << "~Integer()" << endl;
	delete ptr_value;
}

Integer Integer::operator +(Integer const &a) const
{
	cout << "operator +(Integer const&)" << endl;
	return Integer{this->get_value() + a.get_value()};
}

Integer & Integer::operator ++ ()
{
	cout << "& operator ++()" << endl;
	this->set_value(this->get_value() + 1);

	return *this;
}

Integer Integer::operator ++ (int)
{
	cout << "operator ++(int)" << endl;
	Integer temp {*this};

	this->set_value(this->get_value() + 1);

	return temp;
}

bool Integer::operator ==(Integer const &a) const
{
	cout << "bool operator ==(Integer const&)" << endl;
	return this->get_value() == a.get_value();
}

Integer & Integer::operator =(Integer const &a)
{
	cout << "& operator =(Integer const&)" << endl;
	if(this != &a)
	{
		delete ptr_value;
		ptr_value = new int {*a.ptr_value};
	}

	return *this;
}

Integer & Integer::operator =(Integer &&a)
{
	cout << " & operator =(Integer const&&)" << endl;
	if(this != &a)
	{
		delete ptr_value;
		ptr_value = a.ptr_value;
		a.ptr_value = nullptr;
	}

	return *this;
}

void Integer::operator ()() const
{
	cout << "operator()()" << endl;
	cout << this->get_value() << endl;
}

Integer::operator int()
{
	cout << "operator int()" << endl;
	return *ptr_value;
}

Integer operator + (int a, Integer &b)
{
	cout << "operator+(int, Integer&)" << endl;
	Integer result{a + b.get_value()};

	return result;
}
