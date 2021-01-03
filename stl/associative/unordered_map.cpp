// Single-line comment
/*
 * Multiple line comment
 */

#include <iostream>
#include <unordered_map>

using namespace std;

template<typename T1, typename T2>
	void print_items(unordered_map<T1, T2> uom)
	{
		auto itr = uom.begin();
		while(itr != uom.end())
		{
			cout << "Bucket #" << uom.bucket(itr->first) << "\t contains: " << itr->first << ":" << itr->second << endl;
			itr++;
		}
		cout << endl;
	}

template<typename T1, typename T2>
	auto print_stat = [](unordered_map<T1, T2> uom)
	{
		cout << "Bucket count: " << uom.bucket_count() << endl;
		cout << "Size: " << uom.size() << endl;
		cout << "Load factor: " << uom.load_factor() << endl;
	};

template<typename T1, typename T2>
	void print(unordered_map<T1, T2> uom)
	{
		cout << "--------------------------------------" << endl;
		print_items<T1, T2>(uom);
		cout << "--------------------------------------" << endl;
		print_stat<T1, T2>(uom);
		cout << endl;
	};

void _unordered_map()
{
	unordered_map<string, string> uom
	{
		{"Bayer", "BMW"},
		{"Bavaria", "Merceress"}
	};

	uom.insert({"Berlin", "Audi"});
	uom.insert({"Detroyt", "Chevrolett"});
	uom.insert({"Bayer", "BMW"});
	uom.insert({"London", "McLaren"});
	uom.insert({"Tokyo", "Mazda"});

	print(uom);

	uom.insert({"Taxes", "Buick"});

	print(uom);

	
}

int main()
{
	_unordered_map();

	return 0;
}
