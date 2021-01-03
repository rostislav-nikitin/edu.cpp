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

template<typename T1, typename...Params>
	T1* Create(Params&&... args)
	{
		return new T1{std::forward<Params>(args)...};
	}

void print()
{
	std::cout << __PRETTY_FUNCTION__ << endl;
}

template<typename T, typename...Params>
	void print(T p, Params... args)
	{
		//std::cout << __PRETTY_FUNCTION__ << endl;
		std::cout << p;
		if(sizeof...(args) > 0)
		{
			cout << ", ";
		}
		else
		{
			cout << endl;
		}
		print(args...);
	}

int main()
{
	print("a", 1, 44.4, 'c');
	//Employee *em = Create<Employee>("Umar", Integer{100});
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
