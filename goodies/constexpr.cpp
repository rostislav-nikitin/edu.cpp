// Single-line comment
/*
 * Multiple line comment
 */

#include <iostream>

using namespace std;

constexpr int get_number()
{
	return 42;
}

constexpr int add(int x, int y)
{
	return x + y;
}

constexpr int max(int x, int y)
{
	return x > y ? x : y;
}
/* This can not be uses at C++ < C++14, because it not return statement but some conditional statements*/
constexpr int max2(int x, int y)
{
	if(x > y)
		return x;

	return y;
}


int main()
{
	constexpr int i = get_number();
	int arr[i];

	const int j = get_number();
	int arr2[j];

	constexpr int sum = add(3, 5);
	int sum2 = add(4, 6);

	int max_val = max(55, 17);
	int max_val2 = max2(51, 58);

	return 0;
}

/*
 * Constant expression function rules
 * 1. Literal types:
 *   (void, scalar types (int, float, char), references, etc.)
 * 2. Should have an only one line of the code - return statement
 * 3. All constexpr are implicitly inline
*/

/* const idicates that var is constant, but can be evaluated at runtime
 *  constexpr create expression that can be evaluated at compile time
 *  All constexpr variables are const but not the other way round */
