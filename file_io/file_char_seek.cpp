// Single-line comment
/*
 * Multiple line comment
 */

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void write()
{
	std::ofstream out {"test.txt"};
	if(!out)
	{
		out << "Could not open file for writing" << endl;
	}
	std::string message {"C++ was invented by Bjarne"};
	for(char ch : message)
	{
		out.put(ch);
	}
	out.seekp(5);
	out.put('#');

	cout << "Current position is: " << out.tellp() << endl;

}

void read()
{
	std::ifstream input {"test.txt"};
	if(!input)
	{
		cout << "Source file not found" << endl;
	}
	input.seekg(0, std::ios_base::beg);
	cout << "Current position is: " << input.tellg() << endl;
	char ch{};
	while(input.get(ch))
	{
		cout << ch;
	}
	cout << endl;
}

void using_fsteam()
{
	std::fstream stream {"file.txt"};
	if(!stream)
	{
		cout << "FILE DOES NOT EXISTS. CREATING..." << endl;
		std::ofstream out{"file.txt"};
		out.close();
		stream.open("file.txt");
	}

	stream << "Hello world" << endl;
	stream.seekg(0);
	std::string line;
	std::getline(stream, line);
	cout << line << endl;

}

void read_kmsg()
{
	std::ifstream kmsg {"/dev/kmsg"};
	std::string message;
	while(getline(kmsg, message))
	{
		cout << message << endl;
	}
}

int main()
{
	//write();
	//read();
	//using_fsteam();
	read_kmsg();

	return 0;
}
