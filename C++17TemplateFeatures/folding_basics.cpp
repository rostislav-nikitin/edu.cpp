// Single-line comment
/*
 * Multiple line comment
 */

#include <iostream>
#include <sstream>

using namespace std;

// Variadic tempalte
auto sum()
{
	return 0;
}

template<typename T, typename...Args>
	auto sum(T current, Args ...args)
	{
		return current + sum(args...);
	}


//C++17 fold expressions
//Unary

template <typename...Args>
	auto sum_unary_right(Args ...args)
	{
		return (args + ...);
	}
template <typename...Args>
	auto sum_unary_left(Args ...args)
	{
		return (... + args);
	}

template <typename...Args>
	auto sum_binary_right(Args ...args)
	{
		return (args + ... + 0);
	}
template <typename...Args>
	auto sum_binary_left(Args ...args)
	{
		return (0 + ... + args);
	}
/*
 * Fold expressions operators:
 * + - * / % ^ & | = < > << >> += -
 * = *= /= %= ^= &= |= <<= >>= == != <= >= && || , .* ->*
 */
/* If empty args pack list f():
 * && - true
 * || - false
 * ,  - void
 * Other ill-formed
 */

// Unary:
template<typename...Args>
	bool EvenAnyOf(Args ...args)
	{
		return (... || (args % 2 == 0));
	}

template<typename...Args>
	bool EvenAllOf(Args ...args)
	{
		return (... && (args % 2 == 0));
	}



template<typename Predicate, typename ...Args>
	bool AnyOf(Predicate p, Args ...args)
	{
		return (... || p(args));

	}

template<typename ...Args>
	cpp_printf(Args...args)
	{
		return (... << (out << args));
	}

int main()
{
	cout << sum(1, 2, 3, 4, 5) << endl;
	cout << sum_unary_right(1, 2, 3, 4, 5) << endl;
	cout << sum_unary_left(1, 2, 3, 4, 5) << endl;

	// Error:
	//cout << sum_unary_left() << endl;
	cout << sum_binary_right() << endl;
	cout << sum_binary_left(1, 2, 3, 4) << endl;

	// Even:
	cout << "Event any of: " << boolalpha << EvenAnyOf(1, 5, 7) << endl;
	cout << "Event any of: " << boolalpha << EvenAnyOf(1, 5, 8) << endl;
	cout << "Event all of: " << boolalpha << EvenAllOf(1, 5, 8) << endl;
	cout << "Event all of: " << boolalpha << EvenAllOf(2, 4, 8) << endl;
	// Predicate:
	cout << "Any of: " << AnyOf([](int x){ return x % 2 == 0; }, 1, 1, 3) << endl;


	std::ostringstream out {};
	cpp_printf(out, "Hello {0} {1}\n", "Rostislav", "Nikitin");


	return 0;
}
