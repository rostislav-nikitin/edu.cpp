// Single-line comment
/*
 * Multiple line comment
 */

#include <iostream>

using namespace std;

int main()
{
	cout << "Hello world\n" << 45 << " " << 8.2f << endl;

/*	int age;
	cout << "Enter age: ";
	cin >> age;

 	cout << "The age is: " << age << endl; */

	cout << "Enter your name: ";
	char buffer[512];
	cin.getline(buffer, 64, '\n');
	cout << "Your name is: " << buffer;


	return 0;
}
