// Single-line comment
/*
 * Multiple line comment
 */

#include <any>
#include <iostream>

using namespace std;

struct Contact
{
	string name;
	Contact()
	{
		cout << __PRETTY_FUNCTION__ << endl;
	}
	Contact(string name) : name{name}
	{
		cout << __PRETTY_FUNCTION__ << endl;
	}
	Contact(const Contact &contact)
	{
		cout << __PRETTY_FUNCTION__ << endl;
		this->name = contact.name;
	}
	Contact(Contact &&contact)
	{
		cout << __PRETTY_FUNCTION__ << endl;
		this->name = contact.name;
	}
	~Contact()
	{
		cout << __PRETTY_FUNCTION__ << endl;
	}
	string get_name() const
	{
		return this->name;
	}
};

std::ostream & operator << (std::ostream &out, const Contact &contact)
{
	out << contact.get_name();

	return out;
}

int main()
{
	std::any v1 {5};
	//v1 = string{"Hello"};
	//reset() - destroy value
	//has_value() - check has any value

	//v1.reset();	

	if(v1.has_value())
	{
		if(v1.type() == typeid(string))
		{
			cout << std::any_cast<string>(v1) << endl;
		}
		else
		{
			cout << "Wrong type" << endl;
		}

	}
	else
	{
		cout << "Don't have any value" << endl;
	}


	try
	{
		cout << std::any_cast<std::string>(v1) << endl;
	}
	catch(std::exception &ex)
	{
		cout << ex.what() << endl;
	}


	std::any v2 {128};
	v2.reset();
	v2 = string {"Test"};

	cout << std::any_cast<string>(v2) << endl;

	auto v3 = std::make_any<string>("Test3");
	string &v4 = std::any_cast<string&>(v3);
	v4 = "Test4";
	cout << std::any_cast<string>(v3) << endl;
	
	std::any v5 {10};
	int *v6 = std::any_cast<int>(&v5);
	*v6 = 20;
	cout << std::any_cast<int>(v5) << endl;

	std::any contact{Contact{"Slava"}};
	contact.reset();
	contact = 5;
	cout << std::any_cast<int>(contact) << endl;




	return 0;
}
