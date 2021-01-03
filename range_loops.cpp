// Single-line comment
/*
 * Multiple line comment
 */

#include <iostream>

using namespace std;

int main()
{
	int array[] = {1, 2, 3, 4, 5};

	// Simple for loop

	for(int index = 0; index < sizeof(array) / sizeof(array[0]); index++)
	{
		cout << array[index] << " ";
	}

	// Range loop
	for(int current_element : array)
	{
		cout << current_element << " ";	
	}

	// Range loops with auto
	for(auto current_element : array)
	{
		cout << current_element << " ";	
	}
	
	// Range loops with auto
	for(auto current_element : {1, 2, 3, 4, 5})
	{
		cout << current_element << " ";	
	}

	// Range loops with auto
	for(auto const current_element : {1, 2, 3, 4, 5})
	{
		cout << current_element << " ";	
	}

	int *begin = std::begin(array);
	int *end = std::end(array);

	for(;begin != end; begin++)
	{
		cout << *begin << " ";
	}

	return 0;
}
