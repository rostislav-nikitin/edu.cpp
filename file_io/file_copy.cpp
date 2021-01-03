// Single-line comment
/*
 * Multiple line comment
 */

#include <iostream>
#include <fstream>
#include <string>
#include <experimental/filesystem>
	

using namespace std;
using namespace std::experimental::filesystem;

int main()
{
	path source{current_path()};
	source /= "data.txt";

	path dest{current_path()};
	dest /= "data_copy.txt";


	std::ifstream input {source};
	if(!input)
	{
		cout << "Source file not found" << endl;
		return -1;
	}
	std::ofstream output {dest};
	std::string line;

	while(!std::getline(input, line).eof())
	{
		output << line << endl;
	}

	input.close();
	output.close();
	
	return 0;
}
