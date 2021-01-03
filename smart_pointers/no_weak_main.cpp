// Single-line comment
/*
 * Multiple line comment
 */

#include <iostream>

using namespace std;

class Printer
{
	int *ptr_value{};
	public:
		void set_value(int *ptr_value)
		{
			this->ptr_value = ptr_value;
		}

		void print()
		{
			cout << "value is:" << *ptr_value << endl;
		}
};

int main()
{
	Printer prn;
	int num{};

	cin >> num;
	int *ptr_num = new int{num};
	prn.set_value(ptr_num);
	if(*ptr_num > 10)
	{
		delete ptr_num;
		ptr_num = nullptr;
	}

	prn.print();

	delete ptr_num;

	return 0;
}
