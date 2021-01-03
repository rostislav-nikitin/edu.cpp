// Single-line comment
/*
 * Multiple line comment
 */

#include <iostream>
#include <limits>
#include <memory>
#include <vector>

using namespace std;


class Test
{
	public:
		Test()
		{
			std::cout << "Test():Acuire resources" << std::endl;
		}
		~Test()
		{
			std::cout << "~Test():Release resources" << std::endl;
		}
};

void process_records(long long int count)
{
	std::unique_ptr<Test> up {new Test};

	if(count < 10)
	{
		throw std::out_of_range("Count should be greated than 10");
	}
	//int *ptr_array_new = new int[count];
	
	// preserve is analog of the malloc
	std::vector<int> ptr_array_new;
	ptr_array_new.reserve(count);

	std::vector<int> ptr_array;
	ptr_array.reserve(count);

	/*int *ptr_array = (int*)malloc(count * sizeof(int));
	if(ptr_array == nullptr)
	{
		throw std::runtime_error("Failed to allocate memory");
	}*/

	for(long long int i = 0; i < count; ++i)
	{
		ptr_array.push_back(10);
	}

	//free(ptr_array);
	//delete[] ptr_array_new;
	//delete t;

}

int main()
{
	try
	{
		process_records(std::numeric_limits<long long int>::max());
		//process_records(5);
		
	}

	catch(std::runtime_error &ex)
	{
		std::cout << ex.what() << std::endl;
	}
	catch(std::out_of_range &ex)
	{
		std::cout << ex.what() << std::endl;
	}
	catch(std::bad_alloc &ex)
	{
		std::cout << ex.what() << std::endl;
	}
	catch(std::exception &ex)
	{
		std::cout << ex.what() << std::endl;
	}
	catch(...)
	{
		std::cout << "Exception" << std::endl;
	}
	
	return 0;
}
