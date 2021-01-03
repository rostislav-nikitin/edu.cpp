// Single-line comment
/*
 * Multiple line comment
 */

#include <iostream>
#include "overloading_integer.h"

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

void CreateInteger()
{
	/*Integer *ptr = new Integer;
	ptr->set_value(3);
	cout << ptr->get_value() << endl;
	delete ptr;*/

	IntPtr ptr = new Integer;
	ptr->set_value(5);
	cout << (*ptr).get_value() << endl;
}

int main()
{
	CreateInteger();

	return 0;
}
