// Single-line comment
/*
 * Multiple line comment
 */

#include <iostream>

using namespace std;

// Same as: [](int x, int y) -> int
// 		{
// 			return x + y;
// 		}
struct Unnamed
{
	int operator()(int x, int y) const
	{
		return x + y;
	}
};


// Unnamed template
template<typename T>
	struct UnnamedFromTemplate
	{
		T operator()(T x, T y)
		{
			return x + y;
		}
	};

int main()
{
	auto fn = []() {
		std::cout << "Welcome to Lambda expressions" << endl;
	};

	fn();

	cout << typeid(fn).name() << endl;

	auto sum = [](int x, int y) -> int
	{
		return x + y;
	};

	cout << sum(5, 12) << endl;

	Unnamed un;

	cout << un(5, 12) << endl;

	UnnamedFromTemplate<int> unft;

	cout << unft(5, 12) << endl;

	// Generic lambda
	
	auto sum_gen = [](auto x, auto y) noexcept(true)
	{
		return x + y;
	};

	cout << sum_gen(5, 12) << endl;
	
	return 0;
}
