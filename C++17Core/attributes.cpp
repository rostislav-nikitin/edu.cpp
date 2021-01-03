// Single-line comment
/*
 * Multiple line comment
 */

#include <iostream>

using namespace std;

[[deprecated("Use the newer version.")]]
int print(int value)
{
	cout << __PRETTY_FUNCTION__ << "Value :" << value << endl;
	return value;
}

template<typename T>
	[[nodiscard]]
	T print(T value)
	{
		
		cout << __PRETTY_FUNCTION__ << "Value :" << value << endl;
		return value;
	}


class [[deprecated("Class Test is depricated")]] Test
{
};


namespace [[deprecated("Namespace is deprecated")]] A
{
	class Test2
	{
	};
}

class [[nodiscard]] Number
{
};

Number get_number(int x)
{
	return Number{};
}	

int main()
{
	//print(1);
	//print("Test");

	//Test test;
	//A::Test2 test2;
	get_number(5);

	return 0;
}
