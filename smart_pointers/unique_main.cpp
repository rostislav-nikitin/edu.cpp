// Single-line comment
/*
 * Multiple line comment
 */

#include <iostream>
#include <memory>
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


/*void store(std::unique_ptr<Integer> ptr)
{
	cout << "Storing data into a file: " << ptr->get_value() << endl;
}*/

void store(std::unique_ptr<Integer> &ptr)
{
	cout << "Storing data into a file: " << ptr->get_value() << endl;
}

void operate(int value)
{
	std::unique_ptr<Integer> ptr{GetPointer(value)};

	if(ptr == nullptr)
	{
		//ptr = new Integer{value};
		ptr.reset(new Integer{value});
	}

	ptr->set_value(100);
	display(ptr.get());
	//ptr = nullptr;
	ptr.reset(new Integer{});
	*ptr = __LINE__;
	display(ptr.get());
	// Use this if ptr will not used below
	//store(std::move(ptr));
	// Use this if ptr will used below
	store(ptr);
}


int main()
{
	operate(5);

	return 0;
}
