// Single-line comment
/*
 * Multiple line comment
 */

#include <iostream>

using namespace std;

int main()
{
	int x = 10;
	int &ref_x = x;

	cout << "x \t= " << x << "\t &x\t= [" << &x << "]" << endl;
	cout << "ref_x \t= " << ref_x << "\t &ref_x\t= [" << &ref_x << "]" << endl;


	return 0;
}
