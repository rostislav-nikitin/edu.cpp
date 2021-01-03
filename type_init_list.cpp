// Single-line comment
/*
 * Multiple line comment
 */

#include <iostream>
#include "overloading_integer.h"

using namespace std;

class Product
{
	private:
		Integer integer;
		int value;
	public:
		Product(Integer const &in_integer): integer(in_integer), value(integer.get_value())
		{
			cout << "Product(Integer const &)" << endl;
		}
		~Product()
		{
			cout << "~Product" << endl;
		}
};

int main()
{
	Product p{10};

	return 0;
}
