// Single-line comment
/*
 * Multiple line comment
 */

#include <iostream>
#include "oop_class_integer.h"

using namespace std;

Integer add(Integer const &a, Integer const &b)
{
	Integer temp;

	temp.set_value(a.get_value() + b.get_value());

	cout << "add" << endl;

	cout << temp.get_value() << endl;

	return temp;
} 

int main()
{
	Integer a{5}, b{3};

	Integer c(b);

	Integer &&d{8};
	Integer e(d);


	a.set_value(add(a, b).get_value());
	cout << "a.get_value() = " << a.get_value() << endl;

	return 0;
}
