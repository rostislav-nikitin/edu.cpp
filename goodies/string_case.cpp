// Single-line comment
/*
 * Multiple line comment
 */

#include <iostream>
#include <cstring>
#include <string>

using namespace std;

std::string to_upper(const std::string &str);
std::string to_lower(const std::string &str);


int main()
{
	std::string original = {"Hello World"};

	std::string upper = to_upper(original);
	cout << upper << endl;

	std::string lower = to_lower(original);
	cout << lower << endl;

	return 0;
}

std::string to_upper(const std::string &str)
{
	const char *original = str.c_str();
	char head[strlen(original)];
	strcpy(head, original);

	char *current = head;
	while(*current != '\0')
	{
		*current = toupper(*current);
		current++;
	}

	std::string result {head};

	return result;
}

std::string to_lower(const std::string &str)
{
	const char *original = str.c_str();
	char head[strlen(original)];
	strcpy(head, original);

	char *current = head;
	while(*current != '\0')
	{
		*current = tolower(*current);
		current++;
	}

	std::string result {head};
	return result;
}

