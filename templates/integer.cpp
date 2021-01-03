// Single-line comment
/*
 * Multiple line comment
 */

#include <iostream>
#include "integer.h"

using namespace std;

Integer::Integer()
{
	cout << __PRETTY_FUNCTION__ << endl;
	ptr_value = new int{0};
}

Integer::Integer(int value)
{
	cout << __PRETTY_FUNCTION__ << endl;
	ptr_value = new int{value};
}

Integer::Integer(Integer const &obj)
{
	cout << __PRETTY_FUNCTION__ << endl;
	ptr_value = new int{*obj.ptr_value};
}

Integer::Integer(Integer &&obj) noexcept
{
	cout << __PRETTY_FUNCTION__ << endl;
	ptr_value = obj.ptr_value;
	obj.ptr_value = nullptr;
}

int Integer::get_value() const
{
	cout << __PRETTY_FUNCTION__ << endl;
	return *ptr_value;
}

void Integer::set_value(int value)
{
	cout << __PRETTY_FUNCTION__ << endl;
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
	cout << __PRETTY_FUNCTION__ << endl;
	delete ptr_value;
}

Integer Integer::operator +(Integer const &a) const
{
	cout << __PRETTY_FUNCTION__ << endl;
	return Integer{this->get_value() + a.get_value()};
}
/*
Integer & Integer::operator ++ ()
{
	cout << __PRETTY_FUNCTION__ << endl;
	this->set_value(this->get_value() + 1);

	return *this;
}
*/
/*Integer Integer::operator ++ (int)
{
	cout << __PRETTY_FUNCTION__ << endl;
	Integer temp {*this};

	this->set_value(this->get_value() + 1);

	return temp;
}
*/
bool Integer::operator ==(Integer const &a) const
{
	cout << __PRETTY_FUNCTION__ << endl;
	return this->get_value() == a.get_value();
}

Integer & Integer::operator =(Integer const &a)
{
	cout << __PRETTY_FUNCTION__ << endl;
	if(this != &a)
	{
		delete ptr_value;
		ptr_value = new int {*a.ptr_value};
	}

	return *this;
}

Integer & Integer::operator =(Integer &&a)
{
	cout << __PRETTY_FUNCTION__ << endl;
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
	cout << __PRETTY_FUNCTION__ << endl;
	cout << this->get_value() << endl;
}

Integer::operator int()
{
	cout << __PRETTY_FUNCTION__ << endl;
	return *ptr_value;
}

Integer operator + (int a, Integer &b)
{
	cout << __PRETTY_FUNCTION__ << endl;
	Integer result{a + b.get_value()};

	return result;
}
