// Single-line comment
/*
 * Multiple line comment
 */

#include <iostream>
#include "oop_class_integer.h"

using namespace std;

void print(Integer val)
{
	cout << "val = " << val.get_value() << endl;
}


int main()
{
	int const &res = 10;

	Integer a(1);
	Integer b{static_cast<Integer&&>(a)};
	Integer c{5};
	auto d{std::move(c)};

	Integer e{10};
	print(std::move(e));
	// Should crash
	//cout << e.get_value() << endl;
	e.set_value(15);
	cout << "e.value = " << e.get_value() << endl;

	return 0;
}
