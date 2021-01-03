// Single-line comment
/*
 * Multiple line comment
 */

#include <iostream>
#include <sstream>

using namespace std;

class Person
{
	int age;
public:
	Person(int age) : age{age} {}
	void set_age(int age)
	{
		this->age = age;
	}
	int calculate()
	{
		return age * 2;
	}
	auto print()
	{
		return [*this](const string &header)
		{
			std::ostringstream ost;

			ost << header << endl;
			ost << "Age: " << age << endl;

			return ost.str();
		};
	}
};

/*int sum_m(int x, int y)
{
	return x + y;
}*/

int main()
{
	// In C++17 couls be used *this -- capture copy instead of the pointer
	Person *p = new Person{35};

	auto value = p->print();
	p->set_age(40);
	delete p;

	cout << value("##########") << endl;

	// constexpr. Simple lambda implicitly marked as constexpr
	
	auto f = [](int x, int y)
	{
		return x + y;
	};

	constexpr auto sum = f(15, 6);
	cout << sum << endl;
	
	
	return 0;
}
