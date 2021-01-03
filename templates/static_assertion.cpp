// Single-line comment
/*
 * Multiple line comment
 */

#include <iostream>

using namespace std;

int main()
{
	static_assert(sizeof(void *) == 4, "Compile in 32-bit mode only");

	if(sizeof(void *) != 4)
	{
		std::cout << "Not 32-bit mode" << endl;
		return 0;
	}
	else
	{
		//Alrigth
	}
	return 0;
}
