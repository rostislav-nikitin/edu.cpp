// Single-line comment
/*
 * Multiple line comment
 */

#include <iostream>
#include "math.h"

using namespace std;

void print (char ch)
{
	for(int i = 0; i < 10; i++)
	{
		cout << ch;
	}

	cout << endl;
	return;
}

int main()
{
	int x, y;
	cout << "Enter x and y: " << endl;
	cin >> x >> y;
	int sum = add(x, y);

	cout << "The sum is: " << sum << endl;
	print('#');
}


