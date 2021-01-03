// Single-line comment
/*
 * Multiple line comment
 */

#include <iostream>
#include "overloading_integer.h"

using namespace std;

/*Integer operator + (Integer const &a, Integer const &b)
{
	cout << "Integer operator + (Integer const&, Integer const&)" << endl;
	Integer result { a.get_value() + b.get_value() };

	return result;
}*/

std::ostream & operator << (std::ostream &out_stream, Integer const &a)
{
	out_stream << a.get_value();

	return out_stream;
}

std::istream & operator >> (std::istream &in_stream, Integer &a)
{
	int x;
	in_stream >> x;
	*(a.ptr_value) = x;

	return in_stream;
}

int main()
{
	Integer a{10};
	Integer b{20};

	Integer sum = a + b;

	cout << "sum = " << sum.get_value() << endl;

	cout << "++sum = " << (++sum).get_value() << endl;

	cout << "sum++ = " << (sum++).get_value() << endl;

	cout << "sum = " << sum.get_value() << endl;

	cout << "a == a " << ((a == a) ? "true" : "false") << endl;

	cout << "a == b " << ((a == b) ? "true" : "false") << endl;

	Integer c = a;

	c = c;

	cout << "c = " << c.get_value() << endl;

	Integer &&d{};

	Integer e;
	e = d;

	// Type conversion: 5 converted to the Integer
	Integer other_sum = a + 5;
	
	cout << "other_sum = " << other_sum.get_value() << endl;

	Integer one_more_sum = 5 + a;
	
	cout << "one_more_sum = " << one_more_sum << endl;

	Integer f;
	cin >> f;
	cout << f << endl;

	f();

	return 0;
}
