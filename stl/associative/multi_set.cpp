// Single-line comment
/*
 * Multiple line comment
 */

#include <iostream>
#include <set>
#include <functional>

using namespace std;

void _set()
{
	multiset<int, std::greater<int>> s = {0, 1, 5, 19, 4, 2};
	s.insert(5);
	s.insert(5);
	s.insert(5);
	for(auto si : s)
	{
		cout << si << " ";
	}
	cout << endl;

	s.erase(0);
	s.erase(++s.begin());

	auto itr = s.begin();
	while(itr != s.end())
	{
		cout << *itr++ << " ";
	}
	cout << endl;

	itr = s.find(5);
	if(itr == s.end())
	{
		cout << "Not found" << endl;
	}
	else
	{
		cout << "Found" << endl;
	}

	auto fnd = s.equal_range(5);
	while(fnd.first != fnd.second)
	{
		cout << *fnd.first++ << " ";
	}
	cout << endl;

	
}

int main()
{
	_set();

	return 0;
}
