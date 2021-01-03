// Single-line comment
/*
 * Multiple line comment
 */

#include <iostream>


//Add two numbers and return the sum
int add(int *a, int *b) ;    
//Add two numbers and return the sum through the third pointer argument
void add_val(int *a, int *b, int *result); 
//Swap the value of two integers
void swap(int *a, int *b) ;  
//Generate the factorial of a number and return that through the second pointer argument
void factorial(int *a, int *result);       

using namespace std;

int main()
{
	int a = 15, b = 5;
	cout << "a = " << a << ", b = " << b << endl;

	cout << "add = " << add(&a, &b) << endl;

	int result{0};
	add_val(&a, &b, &result);
	cout << "add_val = " << result << endl;

	swap(&a, &b);
	cout << "swap a = " << a << ", b = " << b << endl;

	factorial(&a, &result);
	cout << "factorial = " << result << endl;

	return 0;
}

int add(int *a, int *b)
{
	int result =  *a + *b;

	return result;
}

void add_val(int *a, int *b, int *result)
{
	int sum = *a + *b;
	*result = sum;
}

void swap(int *a, int *b)
{
	int *temp = new int{0};
	*temp = *a;
	*a = *b;
	*b = *temp;
}

void factorial(int *a, int *result)
{
	*result = 1;
	for(int n = 1; n <= *a; n++)
	{
		*result *= n;
	}
}
