// Single-line comment
/*
 * Multiple line comment
 */

#include <iostream>

extern "C" int add(int, int);

double add(double, double);

void print(int *ptr_a);
void print(const int *ptr_ca);

using namespace std;

int main(void)
{
	cout << add(3, 5) << endl;
	cout << add(3.55, 5.12) << endl;
	cout << add(4.55, 5) << endl;

	int a = 64;

	print(&a);

	const int ca = a;

	print(&ca);

	return 0;
}


int add(int a, int b)
{
	int result = a + b;

	return result;
}

double add(double a, double b)
{
	double result = a + b;

	return result;
}

void print(int *ptr_a)
{
	cout << "int *=" << *ptr_a << endl;
}

void print(const int *ptr_ca)
{
	cout << "const int*=" << *ptr_ca << endl;
}
