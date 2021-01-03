// Single-line comment
/*
 * Multiple line comment
 */

#include <iostream>

using namespace std;


void print(int &x)
{
	cout << "print(int &)" << endl;
}

void print(int const &x)
{
	cout << "print(int const &)" << endl;
}

/*void print(int &&x)
{
	cout << "print(int &&)" << endl;
}*/

int main()
{
	int a = 10;
	int &&b = 20;

	int x = 10;
	print(x);

	print(5);

	return 0;
}
