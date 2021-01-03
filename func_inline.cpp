// Single-line comment
/*
 * Multiple line comment
 */

#include <iostream>

// use: g++ -save-temps .. to see *.s with assembly code


int square(int x);

inline int square_inline(int x) __attribute__((always_inline));

#define Square(x) ((x) * (x))

using namespace std;

int main()
{
	int val = 5;

	//int result = square(val);
	//cout << result << endl;

	//result = Square(val + 1);
	//cout << result << endl;
	
	int result = square_inline(val + 1);
	//cout << result << endl;

	return 0;
}

int square(int x)
{
	int result = x * x;

	return result;
}

int square_inline(int x)
{
	return x * x;
}
