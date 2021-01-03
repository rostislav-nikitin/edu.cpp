// Single-line comment
/*
 * Multiple line comment
 */

#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

class Employee
{
	int id;
	string name;
	string prog_lang;
public:
	Employee(int id, string name, string prog_lang) : id{id}, name{name}, prog_lang{prog_lang}
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

	string get_prog_lang() const noexcept
	{
		return prog_lang;
	}

	bool operator < (const Employee &e)
	{
		return id < e.id;
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

struct EmployeeSearchResult
{
	vector<int> ids{};

	void operator () (const Employee &e)
	{
		if(e.get_prog_lang() == "C++")
		{
			ids.push_back(e.get_id());
		}
	}
};

void _vector()
{
	// sort
	vector<Employee> emps 
	{
		Employee{2, "Umar", "C++"},
		Employee{4, "Den", "Pyton"},
		Employee{1, "Ros", "C++"},
		Employee{55, "Dmitry", "C#"},
		Employee{987, "Eugene", "Pascal"}
	};

	std::sort(emps.begin(), emps.end(), 
		[](const Employee &e1, const Employee &e2) -> bool
		{
			return e1.get_name() < e2.get_name();
		});

	for(const auto &x : emps)
	{
		cout << x.get_id() << ":" << x.get_name() << ":" << x.get_prog_lang() << endl;
	}

	// count
	
	int cppCount = std::count_if(emps.begin(), emps.end(), [](const auto &e)
		{
			return e.get_prog_lang() == "C++";
		});

	cout << "C++ count: " << cppCount << endl;	

	// find
	auto find_itr = std::find_if(emps.begin(), emps.end(), [](const auto &e)
		{
			return e.get_prog_lang() == "C#";
		});

	if(find_itr != emps.end())
	{
		cout << "Found C# for: " << find_itr->get_name() << endl;
		find_itr++;
	}
	
	// for-each
	std::for_each(emps.begin(), emps.end(), [](const auto &e)
		{
			cout << e.get_name() << endl;
		});

	auto foundIds = std::for_each(emps.begin(), emps.end(), EmployeeSearchResult{});
	for(int id : foundIds.ids)
		cout << "Id:" << id << endl;
}

struct EmployeeCompare
{
	bool operator () (const Employee &e1, const Employee &e2) const
	{
		return e1.get_id() < e2.get_id();
	}
};

void _set()
{
	set<Employee, EmployeeCompare> emps 
	{
		Employee{2, "Umar", "C++"},
		Employee{4, "Den", "Pyton"},
		Employee{1, "Ros", "C++"},
		Employee{55, "Dmitry", "C#"},
		Employee{987, "Eugene", "Pascal"}
	};

	for(const auto &x : emps)
	{
		cout << x.get_id() << ":" << x.get_name() << ":" << x.get_prog_lang() << endl;
	}
	
}

int main()
{
	_vector();
	cout << "------------------------------------" << endl;
	_set();

	return 0;
}
