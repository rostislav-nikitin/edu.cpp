// Single-line comment
/*
 * Multiple line comment
 */

#include <iostream>
#include <variant>

using namespace std;

struct Number
{
	Number(int num)
	{
		cout << __PRETTY_FUNCTION__ << endl;
	}
	Number()
	{
		cout << __PRETTY_FUNCTION__ << endl;
	}
	~Number()
	{
		cout << __PRETTY_FUNCTION__ << endl;
	}
	Number(const Number& other)
	{
		cout << __PRETTY_FUNCTION__ << endl;
	}
	Number(Number && other)
	{
		cout << __PRETTY_FUNCTION__ << endl;
	}
	Number& operator=(const Number &other)
	{
		cout << __PRETTY_FUNCTION__ << endl;
		if(this == &other)
		{
			return *this;
		}
		return *this;
	}
	Number& operator=(Number &&other)
	{
		cout << __PRETTY_FUNCTION__ << endl;
		if(this == &other)
		{
			return *this;
		}
		return *this;
		
	}
};


int main()
{
	//std::variant<std::string, int, Number> v{Number{5}};
	std::variant<std::string, int, Number> v{10};
	//int val;
	//v = Number{5};
	//std::get<Number>(v) = 10;
	v.emplace<Number>(100);
	std::get<Number>(v);
	//int val;

	try
	{
		//val = std::get<int>(v);
		//val = std::get<1>(v);
		//cout << val << endl;
		//auto active_index = v.index();
		//cout << active_index << endl;
		//auto p = std::get_if<int>(&v);
		//cout << *p << endl;
		/*auto p = std::get_if<int>(&v);
		if (p == nullptr)
		{
			cout << "Not active" << endl;
		}
		else
		{
			cout << "Active" << endl;
		}*/

	}
	catch(std::exception &ex)
	{
		cout << ex.what() << endl;
	}

	return 0;
}
