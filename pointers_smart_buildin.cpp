// Single-line comment
/*
 * Multiple line comment
 */

#include <iostream>
#include "overloading_integer.h"
#include <memory>

using namespace std;

class IntPtr
{
	private:
		Integer *ptr_value;
	public:
		IntPtr(Integer *ptr) : ptr_value(ptr)
		{
		}
		~IntPtr()
		{
			delete ptr_value;
		}

		Integer * operator -> ()
		{
			return ptr_value;
		}

		Integer & operator * ()
		{
			return *ptr_value;
		}
};

void Print(std::unique_ptr<Integer> ptr)
{
	cout << ptr->get_value() << endl;
}

void Print(std::shared_ptr<Integer> ptr)
{
	cout << ptr->get_value() << endl;
	ptr->set_value(10);
}

void CreateInteger()
{
	std::unique_ptr<Integer> p(new Integer);
	(*p).set_value(5);

	Print(std::move(p));

	std::shared_ptr<Integer> psh(new Integer);
	psh->set_value(7);
	Print(psh);
	cout << psh->get_value() << endl;
	/*Integer *ptr = new Integer;
	ptr->set_value(3);
	cout << ptr->get_value() << endl;
	delete ptr;*/

/*	IntPtr ptr = new Integer;
	ptr->set_value(5);
	cout << (*ptr).get_value() << endl;*/
}

int main()
{
	CreateInteger();

	return 0;
}
