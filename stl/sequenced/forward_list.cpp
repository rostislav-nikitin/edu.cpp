// Single-line comment
/*
 * Multiple line comment
 */

#include <iostream>
#include <forward_list>

using namespace std;

void _flist()
{
	forward_list<int> flst = {1, 2, 3, 4, 5};

	for(int i = 0; i < 4; ++i)
		flst.push_front(i * i);

	for(auto flst_item : flst)
	{
		cout << flst_item << " ";
	}
	cout << endl;
	
	auto it = flst.begin();
	flst.insert_after(it, 500);
	flst.erase_after(++it);

	for(auto e : flst)
		cout << e << " ";
	cout << endl;
}

int main()
{
	_flist();

	return 0;
}
