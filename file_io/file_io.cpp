// Single-line comment
/*
 * Multiple line comment
 */

#include <iostream>
#include <fstream>

using namespace std;

void write()
{
	std::ofstream out {"data.txt"};
	out << "Hello world" << endl;
	out << 10 << endl;
	out.close();
}

void read()
{
	std::ifstream input {"data.txt"};
	//input.open("data.txt", ios_base::in); 
	
	if(input.fail())
	{
		cout << "Could not open the file" << endl;
		return;
	}

	if(!input.is_open())
	{
		cout << "Could not open the file" << endl;
		return;
	}

	std::string message;
	std::getline(input, message);

	int value{};
	input >> value;
	input >> value;

	if(input.eof())
	{
		cout << "End of file encountered" << endl;
		input.clear();
		//input.setstate(std::ios_base::failbit);
	}

	if(input.fail())
	{
		cout << "Could not read" << endl;
	}
	
	if(input.good())
	{
		cout << "I/O operations are successful" << endl;
	}
	else
	{
		cout << "Some I/O operation failed" << endl;
	}
	input.close();

	cout << message << ":" << value << endl;
}


int main()
{
	write();
	read();

	return 0;
}
