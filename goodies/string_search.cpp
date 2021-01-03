// Single-line comment
/*
 * Multiple line comment
 */

#include <iostream>
#include <string>

using namespace std;

enum class Case {SENSITIVE, INSENSITIVE};

size_t find(
	const std::string &source,
	const std::string &search_string,
	Case search_case = Case::INSENSITIVE,
	size_t offset = 0);

int main()
{
	std::string str{"Hello World!"};
	std::string search_str = "ORLD!";


	size_t pos = find(str, search_str, Case::INSENSITIVE, 0);
	cout << "Pos = " << pos << endl;

	return 0;
}

size_t find(
	const std::string &source, const std::string &search_string, Case search_case, size_t offset)
{
	size_t 
		result = std::string::npos, 
		srch_idx = 0;

	for(size_t src_idx = offset; src_idx < source.length(); src_idx++)
	{
		if(search_case == Case::SENSITIVE && 
				(search_string[srch_idx] == source[src_idx])
			|| (search_case == Case::INSENSITIVE && 
				(toupper(search_string[srch_idx]) == toupper(source[src_idx]))))
		{
			if((srch_idx + 1) == search_string.length())
			{
				result = src_idx + 1 - search_string.length();
				break;
			}

			srch_idx++;
		}
		else
		{
			srch_idx = 0;
		}
	}

	return result;
}

