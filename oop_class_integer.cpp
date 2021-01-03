// Single-line comment
/*
 * Multiple line comment
 */

#include <iostream>
#include "oop_class_integer.h"

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
