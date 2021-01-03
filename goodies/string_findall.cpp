// Single-line comment
/*
 * Multiple line comment
 */

#include <iostream>
#include <string>
#include <vector>

using namespace std;

enum class Case {SENSITIVE, INSENSITIVE};

std::vector<int> find_all(
	const std::string &source,
	const std::string &search_string,
	Case search_case = Case::INSENSITIVE,
	size_t offset = 0);

int main()
{
	std::string str{"Hello World!"};
	std::string search_str = "L";

	std::vector<int> positions = find_all(str, search_str, Case::INSENSITIVE, 1);
	for(auto pos : positions)
	{
		cout << "Pos = " << pos << endl;
	}

	return 0;
}

std::vector<int> find_all(
	const std::string &source, const std::string &search_string, Case search_case, size_t offset)
{
	std::vector<int> result{};
	size_t srch_idx = 0;

	for(size_t src_idx = offset; src_idx < source.length(); src_idx++)
	{
		if(search_case == Case::SENSITIVE && 
				(search_string[srch_idx] == source[src_idx])
			|| (search_case == Case::INSENSITIVE && 
				(toupper(search_string[srch_idx]) == toupper(source[src_idx]))))
		{
			if((srch_idx + 1) == search_string.length())
			{
				result.push_back(src_idx + 1 - search_string.length());
				srch_idx = 0;
			}
			else
			{
				srch_idx++;
			}
		}
		else
		{
			srch_idx = 0;
		}
	}

	return result;
}

