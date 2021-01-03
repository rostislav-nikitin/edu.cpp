// Single-line comment
/*
 * Multiple line comment
 */

#include <iostream>
#include <cstring>

template <typename T>
	T max(T x, T y)
	{
		std::cout << typeid(T).name() << std::endl;
		return (x > y) ? x : y;
	}
// Explicitly instantiate function template
template char max(char, char);

// Explicit specialization
//template<> const char * max (const char *x, const char *y)
template<>char const * max<char const *>(char const *x, char const *y)
{
	std::cout << __PRETTY_FUNCTION__ << std::endl;
	return strcmp(x, y) > 0 ? x : y;
}


// Non-type template arguments
template<int size>
	void print()
	{
		// non-type argument always const and can not be changed. Can't for example ++size;
		std::cout << size << std::endl;
		char buffer[size];
	}

template<typename T, int size>
	T sum(T (&ptr_arr)[size])
	{
		T sum{};

		for(int i = 0; i < size; ++i)
		{
			sum += ptr_arr[i];
		}

		return sum;
	}

int main()
{
	max(3, 5);
	max(3.5, 2.5);
	// deduction
	max(static_cast<float>(3), 5.6f);
	max<double>(3, 2);

	// instantiate through ptr
	int (*ptr)(int, int) = max;

	// Explicit specialization
	char const *b {"B"};
	char const *a {"A"};

	std::cout << max(a, b) << std::endl;

	// Non-type template arguments 
	// argument is const(compile time) 10, sizeof(i),...
	print<10>();

	// Array
	int arr[]{3, 1, 9, 7};
	int (&ref)[4] = arr;

	// std::begin use this:
	auto it = std::begin(arr);

	int sum_val = sum(arr);
	std::cout << sum_val << std::endl;
	
	
	return 0;
}
