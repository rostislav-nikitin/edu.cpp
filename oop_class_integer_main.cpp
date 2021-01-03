// Single-line comment
/*
 * Multiple line comment
 */

#include <iostream>
#include "oop_class_integer.h"

using namespace std;

void print(Integer value);
Integer add(int x, int y);

int main()
{
	//int *p1 = new int(5);
	// Shallow copy
	//int *p2 = p1;
	// Deep copy
	//int *p3 = new int(*p1);
	
	// Copy constructor is used:
	// 1. Pass object by value to the constructor
	// 2. Invoke function and pass object by value
	// 3. Assign one objec to another: i = i2 (by default shallow copy, but we can implement custom deep copy);

	Integer i(5);
	// Call copy constructor (by default syntesized by the compiler)
	Integer i2(i);
	cout << i.get_value() << endl;

	return 0;
}

void print(Integer value)
{
	cout << value.get_value() << endl;
}

Integer add(int x, int y)
{
	Integer result(x + y);

	return result;
}
