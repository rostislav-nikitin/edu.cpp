// Single-line comment
/*
 * Multiple line comment
 */

#include <iostream>
#include <map>

using namespace std;

struct Person
{
	string name;
	int age;
	string groups[2] {"admin", "user"};

	Person(string name, int age) : name{name}, age{age} 
	{
	}

};

void object_by_value()
{
	cout << "->Object :: By value" << endl;

	Person p = {"Slava", 40};

	auto [name, age, groups] = p;

	cout << name << ":" << age << endl;

	name = "Vasya";

	cout << name << ":" << age << endl;
	cout << p.name << ":" << p.age << endl;
}

void object_by_ref()
{
	cout << "->Object :: By ref" << endl;

	Person p = {"Slava", 40};

	auto &[name, age, groups] = p;

	cout << name << ":" << age << endl;

	name = "Vasya";

	cout << name << ":" << age << endl;
	cout << p.name << ":" << p.age << endl;
}

void arr_by_value()
{
	cout << "->Array :: By value" << endl;
	int arr[] = {1, 3, 5, 15};

	auto [first, second, third, last] = arr;

	first = 10;

	cout << arr[0] << endl;
}

void arr_by_ref()
{
	cout << "->Array :: By ref" << endl;
	int arr[] = {1, 3, 5, 15};

	auto &[first, second, third, last] = arr;

	first = 10;

	cout << arr[0] << endl;
}

void arr_other()
{
	cout << "->Array :: Other" << endl;
	Person p {"Dmitry", 10};
	auto [name, age, groups] = p;

	for(auto group : groups)
	{
		cout << group << " ";
	}
	cout << endl;

	groups[0] = "super admin";

	for(auto group : groups)
	{
		cout << group << " ";
	}
	cout << endl;
}

void other()
{
	cout << "->Other" << endl;
	// pair
	pair<string, string> name {"Invan", "Petrov"};
	auto [first_name, last_name] = name;

	cout << first_name << ":" << last_name << endl;

	// map - for loop
	map<int, string> err_codes
	{
		{0, "Undefined"},
		{1, "Communication error"},
		{2, "Other error"}
	};

	for(auto[code, message] : err_codes)
	{
		cout << code << ":" << message << endl;
	}
	cout << endl;
}

int main()
{
	object_by_value();
	object_by_ref();

	arr_by_value();
	arr_by_ref();

	arr_other();

	other();


	return 0;
}
