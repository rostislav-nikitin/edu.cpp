// Single-line comment
/*
 * Multiple line comment
 */

#include <iostream>
#include <fstream>

using namespace std;

void use_if()
{
	if(int *p = (int *)malloc(sizeof(int)); p != nullptr)
	{
		*p = 50;
		//
		free(p);
	}
	else if (5 == 5)
	{
		cout << (p == nullptr) << endl;
	}
	else
	{
		// There p will be accessible and will be equal to the nullptr
	}
}

void use_switch(int file_error_code)
{
	// swith
	switch(std::ofstream out {"file.txt"};
		file_error_code)
	{
		case 0:
			out << "Invalid parameter" << endl;
			break;
		case 1:
			out << "Could not read form the file" << endl;
			break;
	}
}

int main()
{

	use_if();
	use_switch(0);

	return 0;
}
