// Single-line comment
/*
 * Multiple line comment
 */

#include <iostream>
#include <list>

using namespace std;

void _list()
{
	list<int> lst = {1, 2, 3, 4, 5};

	for(int i = 0; i < 4; ++i)
		lst.push_back(i * i);

	auto it = lst.begin();
	while(it != lst.end())
	{
		cout << *it++ << " ";
	}
	cout << endl;

	it = lst.begin();
	lst.insert(it, 800);
	it = --lst.end();
	lst.erase(it);

	it = lst.begin();
	while(it != lst.end())
	{
		cout << *it++ << " ";
	}
	cout << endl;
}

int main()
{
	_list();

	return 0;
}
