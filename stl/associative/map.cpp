// Single-line comment
/*
 * Multiple line comment
 */

#include <iostream>
#include <map>

using namespace std;

void _map()
{
	map<int, string> m
	{
		{1, "BMW"},
		{2, "Mercedes"},
		{3, "Chrysler"}
	};	

	m.insert(pair<int, string>{4, "Ford"});
	m.insert({15, "Chevrolett"});
	m.insert({15, "Audi"});
	m[0] = "Fiat";

	m.erase(2);

	for(const auto &p : m)
	{
		cout << "key=" << p.first << " value=" << p.second << endl;
	}

	// find
	cout << "m[20]=" << m[20] << endl;

	auto itr = m.find(4);
	if(itr != m.end())
	{
		cout << "Found: " << itr->second << endl;
	}
	else
	{
		cout << "Not Found" << endl;
	}

}

int main()
{
	_map();

	return 0;
}
