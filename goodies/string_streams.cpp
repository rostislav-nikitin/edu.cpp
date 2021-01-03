// Single-line comment
/*
 * Multiple line comment
 */

#include <iostream>
#include <sstream>

using namespace std;

int main()
{
	/*int a{5}, b{6};
	int sum = a + b;


	//std::string output = "Sum of " + a + " & " + b + " is " + sum;
	std::stringstream ss;
//	std::istringstream is;
//	std::ostringstream os;

	
	ss << "Sum of " << a << " & " << b << " is : " << sum << endl;

	std::string s = ss.str();
	//ss.str("Assign to internal buffer");
	cout << s;

	ss.str("");
	ss << sum;
	auto ssum = std::to_string(sum);

	cout << ssum << endl;*/

	std::string data = "12 89 21";
	std::stringstream ss;
	ss.str(data);

	int a;
	while(ss >> a)
	{
		std::cout << a << std::endl;
	}

	// Convert string to integer
	int x = std::stoi("54");
	

	return 0;

}
