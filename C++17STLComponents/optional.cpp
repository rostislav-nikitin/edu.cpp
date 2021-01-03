// Single-line comment
/*
 * Multiple line comment
 */

#include <iostream>
#include <optional>

#define EMPTY_STRING ""

using namespace std;

const char * get_error_string(int error_number)
{

	switch(error_number)
	{
		case 0:
			return "Invalid input";
		case 1:
			return "Connection not established yet";
		default:
			return EMPTY_STRING;
	}
}

std::optional<const char *> get_error_string_opt(int error_number)
{

	switch(error_number)
	{
		case 0:
			return "Invalid input";
		case 1:
			return "Connection not established yet";
		default:
			return std::nullopt;
	}
}

class ContactName
{
	std::string first_name;
	std::optional<std::string> middle_name;
	std::string last_name;
public:
	ContactName(std::string first_name, std::optional<std::string> middle_name, std::string last_name) : first_name {first_name}, middle_name {middle_name}, last_name {last_name}
	{
	
	}
	void print()
	{
		cout << first_name << endl;
		cout << middle_name.value_or("N/A") << endl;
		cout << last_name << endl;
	}
};

int main()
{
	/*auto value = std::make_optional(5);
	if(value.has_value())
	{
		std::cout << value.value() << endl;
	}

	if(value)
	{
		cout << *value << endl;
	}*/

	const char *error_message = get_error_string(1);
	cout << error_message << endl;

	auto error_message_opt_0 = get_error_string_opt(0);
	if(error_message_opt_0.has_value())
	{
		cout << error_message_opt_0.value() << endl;
	}
	else
	{
		cout << "Unknown error number" << endl;
	}

	auto error_message_opt_1 = get_error_string_opt(1);
	if(error_message_opt_1)
	{
		std::cout << *error_message_opt_1 << endl;
	}
	else
	{
		cout << "Unknown error number" << endl;
	}

	// Access std::optnull value without check
	try
	{
		auto err_msg = get_error_string_opt(4);
		cout << err_msg.value() << endl;
	}
	catch(std::exception &ex)
	{
		std::cout << "Exception:" << ex.what() << std::endl;
	}
	// Access std::optional by *value without check
	// Throw error because of call .value() on optnull

	try
	{
		auto err_msg = get_error_string_opt(4);
		cout << err_msg.value() << endl;
	}
	catch(std::exception &ex)
	{
		std::cout << "Exception:" << ex.what() << std::endl;
	}
	// Access std::optional by *value without check
	// Undefined behavior because of *value of optnull
	try
	{
		auto err_msg = get_error_string_opt(4);
		cout << *err_msg << endl;
	}
	catch(std::exception &ex)
	{
		std::cout << "Exception:" << ex.what() << std::endl;
	}

	//std::optional::value_or<T>(T default_value)
	cout << get_error_string_opt(4).value_or("Don't has a value") << endl;

	
	// std::optional can be reused
	std::optional opt_val{5};
	// simply set a new value
	opt_val = 5;
	// or reset value
	opt_val.reset();

	ContactName cn {"Rostyslav", std::nullopt, "Nikitin"};
	cn.print();
		
	return 0;
}
