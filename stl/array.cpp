// Single-line comment
/*
 * Multiple line comment
 */

#include <iostream>
#include <array>

using namespace std;

void _array()
{
	array<int, 5> arr {1, 2, 3, 4, 5};

	for(int arr_item : arr)
	{
		cout << arr_item << " ";
	}
	cout << endl;

	// begin iterator
	auto it_begin = arr.begin();
	// end iterator
	auto it_end = arr.end();
	// size of the array
	int size = arr.size();
	// raw data, could be used to pass to C functions
	auto data = arr.data();

}

int main()
{
	_array();

	return 0;
}
