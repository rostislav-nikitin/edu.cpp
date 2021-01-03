// Single-line comment
/*
 * Multiple line comment
 */

#include <iostream>
#include "overloading_integer.h"

using namespace std;

std::ostream &operator << (std::ostream &out, Integer const &a)
{
	out << a.get_value();

	return out;
}

/*int operator = (int x, Integer const &a)
{
	return a.get_value();
}*/

int main()
{
	// Primitive -> primitive 
	int a{10}, b{20};
	// C-style casting
	float c = (float)a/b;
	cout << c << endl;

	// C++-style casting
	float d = static_cast<float>(a) / b;
	cout << d << endl;

	// C-style
	char *ch = (char *)&d;

	// C++-style
	char *chcpp = reinterpret_cast<char*>(&d);

	// C-style
	char const *chc = (char *)&d;

	// C++-style
	char const *cchar = "A"; 
	char *chccpp = const_cast<char *>(cchar);

	// Primitive -> user-defined
	// Will be found & called suitable constrictor
	Integer h = 10;
	cout << "h = " << h << endl;

	Integer j;
	// Will be next (rvalue will be created, assigned and deleted): j = Integer(15) ;
	j = 15;
	cout << "j = " << j << endl;

	// User defined -> primitive
	int k = static_cast<int>(Integer{55});
	cout << "k = " << k << endl;
	
	

	return 0;
}
