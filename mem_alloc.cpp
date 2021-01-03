#include <stdio.h>
#include <stdlib.h>
#include <iostream>


int alloc_calloc()
{
	//malloc(int) return (void *) pointer which automatically converted to any other type pointer for example to the (int *) one.
	// In the C++ required to cast type explicitly
	//int *p = (int *)malloc(sizeof(int));
	int *p = (int *)calloc(1, sizeof(int));
	// In C if malloc/calloc/realloc can not allocate memory it returns NULL
	if(p == NULL)
	{
		printf("Failed to allocate memory\n");
		return -1;
	}

	*p = 100;

	printf("%d\n", *p);

	free(p);
	// Now p has a same address but now it is a dandling pointer.
	// if we will call free(p) again is will cause to the program crashes
	// Good practice to set p to the NULL
	//free(p);
	p = NULL;
	free(p);

	return 0;
}

void alloc_new()
{
	int *ptr_x = new int{5};
	*ptr_x = 6;

	std::cout << *ptr_x << std::endl;

	delete ptr_x;
	ptr_x = nullptr;
}

int main()
{
	alloc_calloc();
	alloc_new();

	return 0;
}
