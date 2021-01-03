// Single-line comment
/*
 * Multiple line comment
 */

#include <iostream>

using namespace std;
	string cpp_format()
	{
		return "";
	}

template<typename T, typename...Args>
	string cpp_format(T current, Args ...args)
	{
		//string str{args};
		//size_t pos = string::find_first_of(str);
		//string s{};
		//string::string();
		
		return string(current).replace(0, 1, string{args...});
	}

int main()
{
	cout << cpp_format("s s", "def", "ghi") << endl;
	return 0;
}
