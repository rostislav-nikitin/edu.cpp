// Single-line comment
/*
 * Multiple line comment
 */

#include <iostream>
#include <memory>

using namespace std;

class Printer
{
	std::weak_ptr<int> ptr_value{};
	public:
		void set_value(std::weak_ptr<int> ptr_value)
		{
			this->ptr_value = ptr_value;
		}

		void print()
		{
			if(ptr_value.expired())
			{
				cout << "Resource is no more longer available" << endl;
				auto sp = ptr_value.lock();
				cout << "Ref count is: " << sp.use_count() << endl;
			}
			else
			{
				auto sp = ptr_value.lock();
				cout << "value is: " << *sp << endl;
				cout << "Ref count is: " << sp.use_count() << endl;
			}
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
