// Single-line comment
/*
 * Multiple line comment
 */

#include <iostream>
#include <cstring>
#include <string>

using namespace std;

const char * combine(const char *p_first, const char *p_last)
{
	char * result = new char[strlen(p_first) + strlen(p_last) + 1];
	strcpy(result, p_first);
	strcat(result, p_last);

	return result;
}
void using_std_string()
{

	// Initialize & assign
	string s = "Hello";
	s = "Hello String!";
	// Access
	s[0] = 'W';
	char ch = s[1];
	// Size
	std::cout << s << std::endl;
	std::cin >> s;

	std::getline(std::cin, s);

	int len = s.length();

	// Insert
	string s1 {"Hello"}, s2{"World"};
	s = s1 + s2;

	s += s1;
	s.insert(5, "World");

	// Comparison
	if(s1 == s2)
	{
	}

	// Removal
	s.erase(0, 5);
	s.erase();
	s.clear();

	// Search
	auto pos = s.find("World", 1);
	if(pos != string::npos)
	{
		// Found
	}
}

std::string combine(const std::string &first, const std::string & last)
{
	std::string result = first + " " + last;
	return result;
}

int main()
{
	/*char first[10];
	char last[10];

	cin.getline(first, 10);
	cin.getline(last, 10);

	const char *full = combine(first, last);

	cout << "Full name is: " << full << endl;

	delete[] full;*/

	std::string first;
	std::string last;

	std::getline(std::cin, first);
	std::getline(std::cin, last);

	std::string fullname = combine(first, last);

	std::cout << fullname << std::endl;

	// .c_str() -- return C string
	printf("%s", fullname.c_str());

	return 0;
}
