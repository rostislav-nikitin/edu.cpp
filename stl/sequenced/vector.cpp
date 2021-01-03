// Single-line comment
/*
 * Multiple line comment
 */

#include <iostream>
#include <vector>

using namespace std;

void _vector()
{
	vector<int> vec = {1, 2, 3, 4, 5};

	vec[0] = 100;

	for(int i = 0; i < 4; ++i)
		vec.push_back(i * i);

	auto it = vec.begin();
	while(it != vec.end())
	{
		cout << *it++ << " ";
	}
	cout << endl;

	cout << "Size=" << vec.size() << endl;
	vec.insert(vec.begin(), 95);
	cout << "Size=" << vec.size() << endl;
	vec.erase(vec.begin() + 2, vec.begin() + 3);
	//vec.erase(vec.begin() + 2);
	cout << "Size=" << vec.size() << endl;

	for(int i = 0; i < vec.size(); ++i)
	{
		cout << "v[" << i << "]=" << vec[i] << " ";
	}
	cout << endl;

	vec.pop_back();
	cout << "Size=" << vec.size() << endl;

	

}

int main()
{
	_vector();

	return 0;
}
