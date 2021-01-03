#include <stdio.h>
#include <stdlib.h>

int main()
{
	//malloc(int) return (void *) pointer which automatically converted to any other type pointer for example to the (int *) one.
	// In the C++ required to cast type explicitly
	int *p = malloc(sizeof(int));
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
