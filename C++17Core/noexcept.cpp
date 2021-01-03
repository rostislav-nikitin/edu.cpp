// Single-line comment
/*
 * Multiple line comment
 */

#include <iostream>

using namespace std;

void foo() noexcept
{
	cout << __PRETTY_FUNCTION__ << endl;
}

void bar()
{
	cout << __PRETTY_FUNCTION__ << endl;
}

int main()
{
	void (*p)() noexcept;
	
	p = foo;
	// Restrinced in C++17
	//p = bar;
	p();

	return 0;
}
