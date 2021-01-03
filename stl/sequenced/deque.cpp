// Single-line comment
/*
 * Multiple line comment
 */

#include <iostream>
#include <deque>

using namespace std;

void _deque()
{
	deque<int> deq = {1, 2, 3, 4, 5};

	for(int i = 0; i < 4; ++i)
		deq.push_back(i * i);
	for(int i = 0; i < 4; ++i)
		deq.push_front(i * i);

	deq[0] = 100;

	auto it = deq.begin();
	while(it != deq.end())
	{
		cout << *it++ << " ";
	}
	cout << endl;

	cout << "Size=" << deq.size() << endl;
	deq.insert(deq.begin(), 95);
	cout << "Size=" << deq.size() << endl;
	deq.erase(deq.begin() + 2, deq.begin() + 3);
	//vec.erase(vec.begin() + 2);
	cout << "Size=" << deq.size() << endl;

	for(int i = 0; i < deq.size(); ++i)
	{
		cout << "v[" << i << "]=" << deq[i] << " ";
	}
	cout << endl;

	deq.pop_back();
	deq.pop_front();
	cout << "Size=" << deq.size() << endl;
	for(int i = 0; i < deq.size(); ++i)
	{
		cout << "v[" << i << "]=" << deq[i] << " ";
	}

	

}

int main()
{
	_deque();

	return 0;
}
