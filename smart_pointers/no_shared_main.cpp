// Single-line comment
/*
 * Multiple line comment
 */

#include <iostream>
#include <memory>
#include "integer.h"

using namespace std;
class Project
{
};

class Employee
{
	Project *ptr_project;
	public:
		void set_project(Project *ptr_project)
		{
			this->ptr_project = ptr_project;
		}
		Project * get_project() const
		{
			return ptr_project;
		}
};

Employee * assign_project()
{
	Project *ptr_project = new Project();

	Employee ptr_employee = new Employee{};
	ptr_employee->set_project(ptr_project);

	delete ptr_project;

	return ptr_employee;
}

int main()
{

	return 0;
}
