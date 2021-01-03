// Single-line comment
/*
 * Multiple line comment
 */

#include <iostream>

using namespace std;

int main()
{
	std::string filename {"\\usr\\local\\bin"};
	std::cout << filename << std::endl;

	std::string raw_string_message {R"DELIM(C++ introduced filesystem API "(in C++17)")DELIM"};
	std::cout << raw_string_message << std::endl;

	return 0;
}
