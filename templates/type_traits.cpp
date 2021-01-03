// Single-line comment
/*
 * Multiple line comment
 */

#include <iostream>
#include <type_traits>

using namespace std;


template <typename T>
	T divide(T a, T b)
	{
		static_assert(std::is_floating_point<T>::value, "Only floating point type supported");

		T result;
		if(std::is_floating_point<T>::value)
		{
			result = a / b;
		}
		else
		{
			cout << "Use floating point only" << endl;
			result = 0;
		}

		return result;
	}

template<typename T>
	void check(T&&)
	{
		cout 
			<< std::boolalpha
			<< "Is Reference? " 
			<< std::is_reference<T>::value 
			<< endl;

		cout
			<< "After removing: "
			<< std::is_reference<typename std::remove_reference<T>::type>::value
			<< endl;
	}

int main()
{
	cout
		<< std::boolalpha
		<< "In Integer? "
		<< std::is_integral<int>::value
		<< endl;


/*	cout
		<< divide (5, 2)
		<< endl;*/

	cout
		<< divide (5.0, 2.7)
		<< endl;

	
	int ref {};
	check(5);
	check(ref);

	return 0;
}
