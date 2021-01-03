// Single-line comment
/*
 * Multiple line comment
 */
// Use noexcept(true) with move constructors it can help to prefer call them instead of copy constructors and will raise up performace.

#include <iostream>

using namespace std;

void test(int x) noexcept(false)
{
	std::cout << x << std::endl;
	//throw x;
}

int sum(int x, int y) noexcept(noexcept(test(x))) // true by default, false - inform compiler that function may throw exception
{
	test(x);
	return x + y;
}

class A
{
	public:
		// In C++11 all the descructors are by default noexcept(true)
		~A()
		{
			throw 3;
		}
};

int main()
{
	A a;
	std::cout << std::boolalpha << noexcept(a.~A()) << std::endl;
	try
	{
		sum(3, 5);
	}
	catch(int x)
	{
		std::cout << x << std::endl;
	}
	return 0;
}
