// Single-line comment
/*
 * Multiple line comment
 */

#include <iostream>

using namespace std;

auto find_max = [](auto x, auto y)
	{
		return x > y ? x : y;
	};

auto gt = [](auto x, auto y)
	{
		return x > y;
	};

auto lt = [](auto x, auto y)
	{
		return x < y;
	};

template <typename T>
	auto min_max = [](T *itr_begin, T *itr_end)
	{
		T min_value = *itr_begin;
		T max_value = *itr_begin;

		while(itr_begin != itr_end)
		{
			if(*itr_begin < min_value)
			{
				min_value = *itr_begin;
			}			
			if(*itr_begin > max_value)
			{
				max_value = *itr_begin;
			}

			itr_begin++;
		}

		return std::pair<T, T>(min_value, max_value);
	};

template<typename T, int size>
	void print(T (&arr)[size])
	{
		for(auto arr_item : arr)
		{
			cout << arr_item << " ";
		}
		cout << endl;
	}



int main()
{
	cout << "find_max=" << find_max(19, 107) << endl;
	cout << "gt=" << gt(90.1, 50.6) << endl;
	cout << "lt=" << lt(45.87, 21.17) << endl;

	int arr[] = {1, 85, 12, 71, 33};
	auto itr_begin = std::begin(arr);
	auto itr_end = std::end(arr);

	auto mm_res = min_max<int>(itr_begin, itr_end);

	cout << "(" << mm_res.first << ", " << mm_res.second << ")" << endl;

	return 0;
}
