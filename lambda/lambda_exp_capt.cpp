// Single-line comment
/*
 * Multiple line comment
 */

#include <iostream>
#include <fstream>

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



template<typename T, int size, typename Callback>
	void for_each(T (&arr)[size], Callback operation)
	{
		
		for(int i = 0; i < size; ++i)
		{
			operation(arr[i]);
		}
		
		/*
		for(auto &item : arr)
		{
			operation(item);
		}
		*/
		
		
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

template<typename T>
	struct __Unnamed
	{
		T offset;

		__Unnamed(T offset) : offset{offset}
		{
		}

		void operator() (T &x) //const
		{
			cout << "Offset=" << offset << endl;
			x += offset++;
		}
	};


class Product
{
	string name;
	float price;

public:
	Product(const string &name, float price) : name{name}, price{price}
	{
	}

	void assign_final_price()
	{
		float taxes[] { 12, 5, 5 };
		float base_price { price };
		for_each(taxes, [base_price, this](float tax)
		{
			float taxed_price = base_price * tax / 100;
			price += taxed_price;
		});

	}
	float get_price() const
	{
		return price;
	}
};

int main()
{
	//Generalized lambda capture
	// Trivial usage:
	int x {5};
	auto f = [y=x] (int args)
	{
		return y + args;
	};

	cout << f(11) << endl;
	// Usage:
	std::ofstream out {"./file.txt"};

	auto write = [out=std::move(out)](auto value)mutable
	{
		out << value << endl;
	};

	write(255);
	


	return 0;
}

int old_main_5()
{
	//int i = i5;
	// Lambda will be converted into the function pointer. Require empty capure list otherwise will no converted.
	atexit([]()
		{
			std::cout << "Program is exiting ..." << endl;
		});

	return 0;
}

int old_main_4()
{
	cout <<
		[](int x)
		{
			return [](int x) { return x; }(x * 2);
		}(10)
	<< endl;


	return 0;
}

int old_main_3()
{
	Product p {"Watch", 500};
	p.assign_final_price();
	cout << p.get_price() << endl;

	return 0;
}

int old_main_2()
{
	int arr[] {1, 6, 8, 4, 0};

	int offset = 5;
	//for_each(arr, [offset](auto &x){ x += offset; });
	__Unnamed<int> unn{5};
	for_each(arr, unn);
	//for_each(arr, [offset] (auto &x) mutable { x += offset++; });

	for_each(arr, [](auto x){ cout << x << endl; });

	int sum {};

	for_each(arr, [&sum, &offset](auto x) { sum += offset + x; });
	cout << "Sum=" << sum << endl;

	// [=] -- all(declared before)  variables captured by value
	// [&] -- all(decalred before) variables captured by reference	
	// [=, &offset] - all (declared before) by value and &offset by reference
	// [& , offset] - all (declared before) by ref, and offset by value
	// [this] - catpure this class pointer
	// C++17
	// Generalized lambda capture:
	// [var=expression]
	// [&var=expression]
	
	return 0;
}

int old_main()
{

	Comp cmp;
	//cmp(3, 5);

	int arr[5] {5, 1, 3, 8, 2};

	char *carr[5] {"A", "Z", "C", "X", "T"};

	show(arr);

	auto l = [](auto x, auto y) { return x > y; };

	sort(arr, l);

	show(arr);

	cout << "cmp called " << cmp.get_call_count() << " times." << endl;

	
	return 0;
}
