// Single-line comment
/*
 * Multiple line comment
 */

#include <iostream>
#include <variant>

using namespace std;

int main()
{
	std::variant<std::string, int> v{5};
	//int val;
	int val;

	try
	{
		//val = std::get<int>(v);
		//val = std::get<1>(v);
		//cout << val << endl;
		//auto active_index = v.index();
		//cout << active_index << endl;
		//auto p = std::get_if<int>(&v);
		//cout << *p << endl;
		auto p = std::get_if<string>(&v);
		if (p == nullptr)
		{
			cout << "Not active" << endl;
		}
		else
		{
			cout << "Active" << endl;
		}

	}
	catch(std::exception &ex)
	{
		cout << ex.what() << endl;
	}

	return 0;
}
