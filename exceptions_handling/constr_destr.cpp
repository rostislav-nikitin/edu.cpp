// Single-line comment
/*
 * Multiple line comment
 */

#include <iostream>
#include <memory>
#include <vector>

using namespace std;


class A
{
	public:
		A()
		{
			std::cout << "A()" << std::endl;
		}
		~A()
		{
			std::cout << "~A()" << std::endl;
		}
};
class B
{
	public:
		B()
		{
			std::cout << "B()" << std::endl;
		}
		~B()
		{
			std::cout << "~B()" << std::endl;
		}
};
class Test
{

	std::unique_ptr<A> ptr_a{};
	B b{};
	std::unique_ptr<int> ptr_int{};
	//std::unique_ptr<char*> ptr_str{};
	//std::unique_ptr<int*> ptr_arr{};
	std::unique_ptr<std::string> ptr_str{};
	std::unique_ptr<std::vector<int>> ptr_arr{};

	public:
		Test()
		{
			std::cout << "Test():Acuire resources" << std::endl;
			ptr_a.reset(new A);
			//throw std::runtime_error("Failed to initialize");
			//ptr_int.reset(new int{});
			//ptr_str.reset(new std::string{});
			//ptr_arr.reset(new std::vector<int>{});
		}
		~Test()
		{
			std::cout << "~Test():Release resources" << std::endl;
			throw std::runtime_error("Failed to initialize");
			/*delete ptr_a;
			delete ptr_int;
			delete[] ptr_str;
			delete[] ptr_arr;*/
		}
};

int main()
{
	try
	{
		Test t;
	}
	catch(std::runtime_error &ex)
	{
		std::cout << ex.what() << std::endl;
	}
	
	return 0;
}
