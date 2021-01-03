// Single-line comment
/*
 * Multiple line comment
 */

#include <iostream>
#include <initializer_list>
#include <cassert>

using namespace std;

class Bag
{
	int arr[10];
	int size{};
	public:
		Bag() = default;
		Bag(std::initializer_list<int> values)
		{
			auto iterator = values.begin();
			while(iterator != values.end())
			{
				add(*iterator);
				++iterator;
			}
		}
		void add(int value)
		{
			assert(size < 10);
			arr[size++] = value;
		}

		void remove()
		{
			--size;
		}

		int operator[] (int index)
		{
			return arr[index];
		}

		int get_size()
		{
			return size;
		}
};


void print(std::initializer_list<int> values)
{
	for(auto value : values)
	{
		cout << value << endl;
	}
}

int main()
{
	int x {0};
	float y{3.1f};
	int arr[5]{3, 1, 3, 8, 2};
	std::string s {"Hello C++"};

	std::initializer_list<int> data = {1, 2, 3, 4};
	auto values = {1, 2, 3, 4};
	Bag empty_bag;



	Bag b{3,1,8};
	/*b.add(3);
	b.add(1);
	b.add(8);*/

	for(int i = 0; i < b.get_size(); ++i)
	{
		cout << b[i] << " ";
	}

	cout << endl;

	//print(values); or
	print({8, 2, 6, 7});

	for(auto value : {1, 2, 3, 4})
		cout << value << " ";

	cout << endl;

	
	return 0;
}
