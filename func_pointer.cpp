// Single-line comment
/*
 * Multiple line comment
 */

#include <iostream>

using namespace std;

void print(int, char);

void end_message()
{
	cout << "End of the program" << endl;
}

int main()
{

	atexit(end_message);
	print(5, '#');
	void (*ptr_fn) (int, char) = &print;
	(*ptr_fn)(8, '@');
	ptr_fn(10, '%');
	cout << "End of main" << endl;

	return 0;
}


void print(int count, char ch)
{
	for(int idx = 0; idx < count; idx++)
	{
		cout << ch;
	}
	cout << endl;
}
