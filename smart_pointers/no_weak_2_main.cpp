// Single-line comment
/*
 * Multiple line comment
 */

#include <iostream>
#include <memory>

using namespace std;

class Printer
{
	std::shared_ptr<int> ptr_value{};
	public:
		void set_value(std::shared_ptr<int> ptr_value)
		{
			this->ptr_value = ptr_value;
		}

		void print()
		{
			cout << "Ref count is: " << ptr_value.use_count() << endl;
			cout << "value is: " << *ptr_value << endl;
		}
};

int main()
{
	Printer prn;
	int num{};

	cin >> num;
	std::shared_ptr<int> ptr_num{new int{num}};
	prn.set_value(ptr_num);
	prn.print();
	if(*ptr_num > 10)
	{
		ptr_num = nullptr;
		// or ptr_num.reset();
	}

	prn.print();

	return 0;
}
