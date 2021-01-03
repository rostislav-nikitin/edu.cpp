// Single-line comment
/*
 * Multiple line comment
 */

#include <iostream>

int main()
{
	int x = 10;
	std::cout << "addres of x = " << &x << "\n" << std::endl;

	// Address of operator: &

	int *ptr_x = &x;
	std::cout << "the *ptr_x = " << ptr_x << "\n" << std::endl;

	// Void pointer could point to the variable of the any data-type
	void *void_ptr_x = &x;
	std::cout << "the *void_ptr_x = " << void_ptr_x << "\n" << std::endl;

	// By default pointers are initialized with a some randome addres (it not initialized explicitly).
	void *uninitialized_void_ptr_x;
	std::cout << "the *void_ptr_x = " << uninitialized_void_ptr_x << "\n" << std::endl;

	// De-referencing operator: *
	*ptr_x = 5;
	std::cout << "x = " << x << "\n" << std::endl;
	// Read
	int y = *ptr_x;
	std::cout << "y = " << y << "\n" << std::endl;

	// NULL pointer
	// C & pre-C++ NULL is a macro
	// NULL is equal to 0 (in the most compilers)
	//
	// In C++1 intoduced new type: nullptr. It is type-safe and better then NULL-macro
	// Always use nullptr istead of NULL macro
	//
	void *void_null_pointer = nullptr;

	int *int_null_pointer = nullptr;

	// Try to read from the *int_null_pointer(should be Segmentation fault)
	//std::cout << "*int_null_pointer = " << *int_null_pointer << std::endl;

	// Try to write to *int_null_pointer (should be Segmentation error)
	*int_null_pointer = 5;

	// Try to read from the *int_null_pointer(should be Segmentation fault)
	//std::cout << "*int_null_pointer = " << *int_null_pointer << std::endl;
}
