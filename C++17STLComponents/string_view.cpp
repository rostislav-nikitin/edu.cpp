// Single-line comment
/*
 * Multiple line comment
 */

#include <iostream>
#include <string_view>

using namespace std;
using namespace std::string_view_literals;

int main()
{
	string_view sv0 = "Hello world";

	string str1 {"Hello"};
	string_view sv1 = str1;

	auto sv2 = "Using\0literals"sv;

	cout << "size: " << sv2.size() << endl;
	cout << sv2 << endl;
	cout << "data(): " << sv2.data() << endl;

	// [] - don't check boundaries, coul product undefined behavior
	cout << sv2[0] << endl;
	// .at(index) - check boundaries
	cout << sv2.at(0) << endl;

	auto pos = sv2.find("literals");
	if(pos != std::string::npos)
		cout << "pos: " << pos << endl;


	// change pointer
	sv2.remove_prefix(3);
	cout << sv2 << endl;

	sv2.remove_suffix(2);
	cout << sv2 << endl;

	auto sv3 = sv0.substr(0, 5);
	cout << sv3 << endl;

	return 0;
}
