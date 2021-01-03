// Single-line comment
/*
 * Multiple line comment
 */

#include <iostream>
#include "integer.h"

using namespace std;

class Employee
{
	std::string name;
	Integer id;

	public:
/*
		Employee(const std::string &name, const Integer &id):name {name}, id{id}
		{
			std::cout << __PRETTY_FUNCTION__ << std::endl;
		}

		Employee(const std::string &&name, Integer &&id):name{name}, id{std::move(id)}
		{
			std::cout << __PRETTY_FUNCTION__ << std::endl;
		}
*/

		template<typename T1, typename T2>
			Employee(T1 &&name, T2 &&id) :
				name{std::forward<T1>(name)}, id{std::forward<T2>(id)}
			{
			}

		std::string get_name() const noexcept
		{
			return name;
		}
		void set_name(std::string name)
		{
			this->name = name;
		}
};
/*
void test(Employee val)
{
	val.set_name("temp");
}
*/

template<typename T1, typename T2, typename T3>
	T1* Create(T2 &&name, T3 &&id)
	{
		return new T1
		{
			std::forward<T2>(name), 
			std::forward<T3>(id)
		};
	}

int main()
{
	Employee *em = Create<Employee>("Umar", Integer{100});
	//Employee emp { "Umar", Integer {100} };
	/*std::string name {"Umar"};
	Integer id {10};

	Employee emp2 {name, id};*/
/*	
	Employee t {"Umar", 10};

	test(t);

	std::cout << t.get_name() << std::endl;	
*/


	return 0;
}
