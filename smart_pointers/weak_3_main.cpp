// Single-line comment
/*
 * Multiple line comment
 */

#include <iostream>
#include <memory>

using namespace std;

class Employee;

class Project
{
	public:
		weak_ptr<Employee> ptr_employee;

		Project()
		{
			cout << "Project()" << endl;
		}
		~Project()
		{
			cout << "~Project()" << endl;
		}
};

class Employee
{
	public:
		shared_ptr<Project> ptr_project;
		Employee()
		{
			cout << "Employee()" << endl;
		}
		~Employee()
		{
			cout << "~Employee()" << endl;
		}
};

int main()
{
	shared_ptr<Employee> emp {new Employee{}};
	shared_ptr<Project> prj {new Project{}};

	emp->ptr_project = prj;
	prj->ptr_employee = emp;

	//delete emp;
	//delete prj;

	return 0;
}
