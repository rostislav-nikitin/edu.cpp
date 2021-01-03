#include <iostream>
#include <cstring>

int main()
{
	int *ptr_arr = new int[5];

	ptr_arr[1] = 10;

	std::cout << ptr_arr[1] << std::endl;

	delete []ptr_arr;

	ptr_arr = nullptr;

	// Uniform initialization
	int *ptr_arru = new int[5] {1, 2, 3, 4, 5};

	for(int idx = 0; idx < 5; idx++)
	{
		std::cout << ptr_arru[idx] << " ";
	}

	std::cout << std::endl;

	delete []ptr_arru;

	ptr_arru = nullptr;

	// String : char array
	
	char *ptr_str = new char[4];
	strcpy(ptr_str, "C++");
	std::cout << ptr_str << std::endl;

	delete []ptr_str;

	// 2D arrays
	// 	2D stack array
	int p_arr2dstack[2][3] =
	{
		1, 2, 3,
		4, 5, 6
	};

	// 	2D heap array
	int *p_arr2dheap1_row1 = new int[3];
	int *p_arr2dheap1_row2 = new int[3];

	int **p_arr2dheap1 = new int *[2];

	p_arr2dheap1[0] = p_arr2dheap1_row1;
	p_arr2dheap1[2] = p_arr2dheap1_row2;

	p_arr2dheap1[0][1] = 10;

	std::cout << p_arr2dheap1[0][1] << std::endl;

	delete []p_arr2dheap1_row1;
	delete []p_arr2dheap1_row2;

	delete []p_arr2dheap1;

	//	2D heap array (short)
	int *ptr_arr2d = new int[5,10];

	delete []ptr_arr2d;
	ptr_arr2d = nullptr;


	return 0;
}
