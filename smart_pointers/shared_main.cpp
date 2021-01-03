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
	public:
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
	std::shared_ptr<Project> ptr_project;
	public:
		void set_project(std::shared_ptr<Project> ptr_project)
		{
			this->ptr_project = ptr_project;
		}
		std::shared_ptr<Project> get_project() const
		{
			return ptr_project;
		}
};

std::shared_ptr<Employee> assign_project()
{
	std::shared_ptr<Project> ptr_project{new Project{}};

	Employee *ptr_employee = new Employee{};
	ptr_employee->set_project(ptr_project);

	//delete ptr_project;

	return std::shared_ptr<Employee>(ptr_employee);
}

int main()
{
	auto sp = assign_project();

	// Check is share pointer points to something
	if(sp == nullptr)
	{
	}

	sp.get(); // Get the undelying pointer

	sp.reset(new Employee{}); // Decrease pointer counter by 1, set underlying pointer to another value

	return 0;
}
