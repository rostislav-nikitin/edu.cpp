// Single-line comment
/*
 * Multiple line comment
 */

#include <iostream>
#include <set>

using namespace std;

void _set()
{
	set<int> s = {0, 1, 5, 19, 4, 2};
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

	itr = s.find(4);
	if(itr == s.end())
	{
		cout << "Not found" << endl;
	}
	else
	{
		cout << "Found" << endl;
	}

	

	
}

int main()
{
	_set();

	return 0;
}
