// Single-line comment
/*
 * Multiple line comment
 */

#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int arr[10];
	int *ptr = new int[10];
	for(int i = 0; i < 10; ++i)
	{
		ptr[i] = i * 10;
	}

	std::vector<int> data{1, 2, 3, 4};
	data.push_back(4);

	for(int i = 0; i < 5; ++i)
	{
		data.push_back(i* 10);
	}

	// Access
	for(int i = 0; i < data.size(); ++i)
	{
		cout << data[i] << " ";
	}

	for(auto value : data)
	{
		cout << value << " ";
	}
	
	/*auto it = data.begin();
	cout << *it;
	++it;*/

	// Delete
	auto it = data.begin();
	data.erase(it);
	cout << endl;

	for(auto value : data)
	{
		cout << value << " ";
	}

	// Insert
	it = data.begin() + 5;
	data.insert(it, 500);
	cout << endl;
	for(auto value : data)
	{
		cout << value << " ";
	}

	cout << endl;

	return 0;
}
