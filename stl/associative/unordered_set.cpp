// Single-line comment
/*
 * Multiple line comment
 */

#include <iostream>
#include <unordered_set>

using namespace std;

template<typename T>
	void print_items(unordered_set<T> uos)
	{
		auto itr = uos.begin();
		while(itr != uos.end())
			cout << "Bucket #" << uos.bucket(*itr) << "\t contains: " << *itr++ << endl;
		cout << endl;
	}

template<typename T>
	auto print_stat = [](unordered_set<T> uos)
	{
		cout << "Bucket count: " << uos.bucket_count() << endl;
		cout << "Size: " << uos.size() << endl;
		cout << "Load factor: " << uos.load_factor() << endl;
	};

template<typename T>
	void print(unordered_set<T> uos)
	{
		cout << "--------------------------------------" << endl;
		print_items<T>(uos);
		cout << "--------------------------------------" << endl;
		print_stat<T>(uos);
		cout << endl;
	};

void _unordered_set()
{
	unordered_set<string> uos
	{
		"BMW",
		"Merceress"
	};

	uos.insert("Audi");
	uos.insert("Chevrolett");
	uos.insert("BMW");
	uos.insert("McLaren");
	uos.insert("Mazda");

	print<string>(uos);

	uos.insert("Buick");

	print(uos);

	
}

int main()
{
	_unordered_set();

	return 0;
}
