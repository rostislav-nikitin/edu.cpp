// Single-line comment
/*
 * Multiple line comment
 */

#include <iostream>
#include <experimental/filesystem>

using namespace std;
using namespace std::experimental::filesystem;

int main()
{
	path p{R"(./)"};

	if(p.has_filename())
	{
		cout << p.filename() << endl;	
	}

	for(const auto &x : p)
	{
		cout << x << endl;
	}

	directory_iterator beg { p };
	directory_iterator end {};

	while(beg != end)
	{
		std::cout << *beg << endl;
		++beg;
	}

	return 0;
}
