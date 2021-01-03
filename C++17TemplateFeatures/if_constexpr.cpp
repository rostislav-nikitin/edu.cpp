// Single-line comment
/*
 * Multiple line comment
 */

#include <iostream>

using namespace std;

template<typename T>
	void print(const T &value)
	{
		if constexpr(std::is_pointer_v<T>)
		{
			cout << *value << endl;
		}
		else if constexpr(std::is_array_v<T>)
		{
			for(auto elem : value)
				cout << elem << " ";

			cout << endl;
		}
		else
		{
			cout << value << endl;
		}
	}

template<typename T>
	string to_string(T value)
	{
		if constexpr(std::is_arithmetic_v<T>)
		{
			return std::to_string(value);
		}
		else
		{
			return string{value};
		}
	}

void test_pl()
{
	if (sizeof(void *) == 4)
	{
		cout << "32-bit mode" << endl;
	}
	else if (sizeof(void *) == 8)
	{
		cout << "64-bit mode" << endl;
	}
	else
	{
		cout << "Unkonwn mode" << endl;
	}
}

int main()
{
	// First
	/*
	int value {5};
	print(value);

	print(&value);

	int values[3] {1, 2, 3};
	print(values);
	*/
	// Second
		
	
	/*int value {10};
	
	cout << to_string(5) << endl;
	cout << to_string(value) << endl;*/

	test_pl();

	return 0;
}
