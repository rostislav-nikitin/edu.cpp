// Single-line comment
/*
 * Multiple line comment
 */

#include <iostream>

using namespace std;

void print(int const &x)
{
	cout << "x = " << x << endl;
}

int main()
{
	// Pointers
	const int x = 10;
	// This should cause to compilation error (const int value)
	//x = 15;
	
	int const *ptr_x;
	// This should cause to compilation error (pointer to the const int value)
	//*prt_x = 20;

	// This should cause to compilation error (pointer to non-const value assignment to const value)
	//int *y = &x;

	// This should cause to compilation error (pointer to non-const value assignment to const pointer)
	//int *z = x;

	const int *w = &x;

	const int *const cptx_x = &x;

	// This should cause to compilation error (const pointer assignment)
	//cptx_x = ptr_x;

	// References
	int const &ref_x = 20;

	print(ref_x);
	print(10);	


	return 0;
}
