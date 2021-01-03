// Single-line comment
*
 * Multiple line comment
 */

#include <iostream>

int main()
{
	
	// C++98
	// Scalar types can be initialize with = or ()
	// Array types with {}
	// If used = then it's name: copy initialization
	int uninitialize;
	int initialized = 5;
	int initialized_anoter_way(5); // Direct init

	std::string initialized_by_constructor;
	std::string initialized_explicitly("C++"); // Direct init
	// Arrays

	char uninitialized[9];
	char initialized[8] = {'\0'};
	char initialized2 = {'h', 'e', 'l', 'l', 'o'}; // Aggregate initialization
	char initialized = {"abcd"};
	// C++11
	// Uniform initialization for scalar and array types
	//  {} - for all the types init
	int initialized{}; //Value initialization
	int initialized{5}; // Direct initialization
	//int func(); // !!!Func will be created: most vexing parse
	// Arrays
	char initialized[8]{} //- Initialzied with defaule values
	char initialized[9]{"Hello"}//Direct initialization

	int *p_uninit = new int{}; // Default value
	char *p_uninit_char = new char[8]{}; // All array items will have a default values
	char *p_init = new char[8]{"Hello"};

	// Rules
	// For primitive types on your choise (assignment | uniform)
	// For used-defined types use uniform init always 
	/*
	 * Value initialization => T obj{};
	 * Direct initialization T obj{v};
	 * Copy initialization = T obj = v;
	 */
	/* Advantages of uniform initialization
	 * 1. If forces initialization
	 * 2. You can use direct initialization for array types
	 * 3. It prevents narrowing conversions
	 * 4. Uniform syntax for all types
	 */
