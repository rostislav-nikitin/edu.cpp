// Single-line comment
/*
 * Multiple line comment
 */

#include <iostream>
#include <limits>

using namespace std;

int process_records(long long int count)
{
	int result;

	int *ptr_array = (int*)malloc(count * sizeof(int));
	if(ptr_array != nullptr)
	{

		for(long long int i = 0; i < count; ++i)
		{
			ptr_array[i] = 10;
		}

		free(ptr_array);
		result = 0;
	}
	else
	{
		cout << "Failed to allocate memory" << endl;
		result = -1;
	}

	return result;
}

int main()
{
	if(process_records(std::numeric_limits<long long int>::max()))
	{
	}
	return 0;
}
