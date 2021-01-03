// Single-line comment
/*
 * Multiple line comment
 */

#include <iostream>
#include "integer.h"


using namespace std;

void display(Integer *ptr)
{
	if(ptr)
	{
		cout << ptr->get_value() << endl;
	}
}

Integer * GetPointer(int value)
{
	Integer *ptr = new Integer{value};
	return ptr;
}

void operate(int value)
{
	Integer *ptr = GetPointer(value);
	if(ptr == nullptr)
	{
		ptr = new Integer{value};
	}
	ptr->set_value(100);
	display(ptr);
	delete ptr;
	ptr = nullptr;
	ptr = new Integer{};
	*ptr == __LINE__;
	display(ptr);
	delete ptr;
}


int main()
{
	operate(5);

	return 0;
}
