// Single-line comment
/*
 * Multiple line comment
 */

#include <iostream>

using namespace std;

class Employee;

class Project
{
	public:
		Employee *ptr_employee;
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
		Project *ptr_project;
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
	Employee *emp = new Employee();
	Project *prj = new Project();

	emp->ptr_project = prj;
	prj->ptr_employee = emp;

	delete emp;
	delete prj;

	return 0;
}
