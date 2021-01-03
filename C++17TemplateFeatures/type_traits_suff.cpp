// Single-line comment
/*
 * Multiple line comment
 */

#include <iostream>

using namespace std;

class Person
{
	string name;
public:
	Person() = default;
	Person(string name) : name{name}
	{
	}
};

template<typename T>
	void check(T &&value)
	{
		value = 50;
		cout << boolalpha << std::is_reference_v<T> << endl;
		cout << boolalpha << std::is_reference_v<typename std::remove_reference_t<T>> << endl;
	}

int main()
{
	//static_assert(std::is_constructible<Person>::value, "Can not be serialized/de-serialized (lack of default constructor");
	static_assert(std::is_constructible_v<Person>, "Can not be serialized/de-serialized (lack of default constructor");
	
	int x = 10;
	check(x);
	cout << "&x=" << x << endl;
	int &y = x;
	check(y);
	int &&z = 20;
	check(z);
	check(20);


	return 0;
}
