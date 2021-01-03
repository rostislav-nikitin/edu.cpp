// Single-line comment
/*
 * Multiple line comment
 */

#include <iostream>

using namespace std;

int main()
{
	// Variables
	auto x = 10;

	auto y = x;

	auto z = x + y;

	cout << "x = " << x << " y = " << y << " z = " << z << endl;

	auto const cx = 15;

	auto cy = cx;
	// cy is not a const (simpy copied value of the cx to the new cy space at stack);
	cy = 20;

	// References
	// auto -> const int
	auto &ref_cx = cx;
	//ref_cx = 25; // Should be compile time error

	// auto -> int
	auto &ref_cy = cy;
	ref_cy = 35;

	// Pointers
	auto prt_cx = &cx;
	//*prt_cx = 50; // Should be an error (pointer to const)

	auto ptr_cy = &cy;
	*ptr_cy = 100;
	

	return 0;
}
