// Single-line comment
/*
 * Multiple line comment
 */

#include <iostream>

using namespace std;

void swap_ptr(int *, int *);
void swap_ref(int &, int &);

int main()
{ 
	int a = 5, b = 10;

	cout << "[BEFORE] a\t= " << a << "\t[" << &a << "], b\t= " << b << "\t[" << &b << "]" << endl;
	swap_ptr(&a, &b);	
	cout << "[AFTER]  a\t= " << a << "\t[" << &a << "], b\t= " << b << "\t[" << &b << "]" << endl;

	cout << "[BEFORE] a\t= " << a << "\t[" << &a << "], b\t= " << b << "\t[" << &b << "]" << endl;
	swap_ref(a, b);	
	cout << "[AFTER]  a\t= " << a << "\t[" << &a << "], b\t= " << b << "\t[" << &b << "]" << endl;
	
	return 0;
}

void swap_ptr(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

void swap_ref(int &a, int &b)
{
	int temp = a;
	a = b;
	b = temp;
}
