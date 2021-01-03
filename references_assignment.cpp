// Single-line comment
/*
 * Multiple line comment
 */

#include <iostream>
//Add two numbers and return the result thro    ugh a reference parameter
void add(int a,int b, int &result);
//Find factorial of a number and return that through a reference parameter
void factorial(int a, int &result);
//Swap two numbers through reference arguments
void swap(int &a, int &b);

using namespace std;

int main()
{
	int a = 5, b = 20;
	int result;

	cout << "a = " << a << " b = " << b << endl;

	add(a, b, result);
	cout << "add(a, b) = " << result << endl;

	factorial(a, result);
	cout << "factorial(a) = " << result << endl;

	swap(a, b);
	cout << "swap(&a, &b) a = " << a << " b = " << b << endl;

	return 0;
}

void add(int a, int b, int &result)
{
	result = a + b;
}

void factorial(int a, int &result)
{
	result = 1;
	for(int n = 1; n <= a; n++)
	{
		result *= n;
	}
}
void swap(int &a, int &b)
{
	int temp = a;
	a = b;
	b = temp;
}
