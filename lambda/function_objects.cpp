// Single-line comment
/*
 * Multiple line comment
 */

#include <iostream>

using namespace std;


//using Comparator = bool (*)(int, int);

template<typename T, int size, typename C>
	void sort(T (&arr)[size], C &comp)
	{
		for(int i = 0; i < size; ++i)
		{
			for(int j = 0; j < size - i - 1; ++j)
			{
				if(comp(arr[j], arr[j+1]))
				{
					T temp = std::move(arr[j]);
					arr[j] = std::move(arr[j+1]);
					arr[j+1] = std::move(temp);
				}
			}
		}
	}

template <typename T, int size>
	void show(T (&arr)[size])
	{
		cout << "{";
		for(int i = 0; i < size; ++i)
		{
			cout << arr[i] << " ";
		}
		cout << "}" << endl;
	}

bool comp_asc(int x, int y)
{
	return x > y;
}

bool comp_desc(int x, int y)
{
	return y > x;
}


struct Comp
{
	int call_count = 0;
	bool operator()(int x, int y)
	{
		++call_count;
		return x > y;
	}

	int get_call_count()
	{
		return call_count;
	}
};

int main()
{

	Comp cmp;
	//cmp(3, 5);

	int arr[5] {5, 1, 3, 8, 2};

	char *carr[5] {"A", "Z", "C", "X", "T"};

	show(arr);

	sort(arr, cmp);

	show(arr);

	cout << "cmp called " << cmp.get_call_count() << " times." << endl;

	
	return 0;
}
