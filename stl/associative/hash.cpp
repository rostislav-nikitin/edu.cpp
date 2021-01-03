// Single-line comment
/*
 * Multiple line comment
 */

#include <iostream>
#include <unordered_set>

using namespace std;

class Employee
{
	int id;
	string name;
public:
	Employee(int id, string name) : id{id}, name{name}
	{
	}

	int get_id() const noexcept
	{
		return id;
	}

	string get_name() const noexcept
	{
		return name;
	}
};

//auto EmployeeHash = [](const Employee & emp) -> size_t
struct EmployeeHash
{
	size_t operator()(const Employee &emp) const
	{
		auto s1 = hash<int>{}(emp.get_id());
		auto s2 = hash<string>{}(emp.get_name());

		auto result = s1 ^ s2;

		return result;
	}
};

//auto EmployeeEquality = [](const Employee &e1, const Employee &e2) -> bool
struct EmployeeEquality
{
	bool operator()(const Employee &e1, const Employee &e2) const
	{
		return e1.get_id() == e2.get_id();
	}
};

void _hash()
{
	// hash
	string s = "Hello world!";
	hash<string> h;
	cout << s << " -> " << h(s) << endl;

	// Custom types 
	unordered_set<Employee, EmployeeHash, EmployeeEquality> emps {};

	emps.insert(Employee{1, "Ros"});
	emps.insert(Employee{2, "Umar"});
	emps.insert(Employee{4, "Den"});
	emps.insert(Employee{55, "Dmitry"});
	emps.insert(Employee{987, "Eugene"});

	for(const auto &x : emps)
	{
		cout << "Bucket #" << emps.bucket(x) << "\t " << x.get_id() << ":" << x.get_name() << endl;
	}

}

int main()
{
	_hash();

	return 0;
}
