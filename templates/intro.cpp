// Single-line comment
/*
 * Multiple line comment
 */

#include <iostream>
#include <cstring>

#include "intro.h"

/*int max(int x, int y)
{
	return (x > y) ? x : y;
}

float max(float x, float y)
{
	return (x > y) ? x : y;
}*/

int main()
{
	// max
	std::cout << max(5, 6) << std::endl;
	std::cout << max(1.2, 17.6) << std::endl;

	// array sum
	int arr[] = {5, 12, 22};
	std::cout << array_sum(arr) << std::endl;
	
	// array max
	std::cout << max(arr) << std::endl;

	// array min_max
	auto mm_result = min_max(arr);
	std::cout << "min=" << mm_result.first << std::endl;
	std::cout << "max=" << mm_result.second << std::endl;

	// array of char *
	char const * char_arr[] = {"F", "A", "Z", "T"};
	std::cout << max(char_arr) << std::endl;

	// array of string
	std::string str[] {"F", "A", "Z", "T"};
	std::cout << max(str) << std::endl;

	return 0;
}
