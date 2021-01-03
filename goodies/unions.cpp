// Single-line comment
/*
 * Multiple line comment
 */

#include <iostream>

using namespace std;

union Test
{
	int x;
	char ch;
	double d;

	Test() : ch{'A'}/*, x{10} : Cannot initialize multiple members, only one */
	{
		cout << __PRETTY_FUNCTION__ << endl;
	}

	~Test()
	{
		cout << __PRETTY_FUNCTION__ << endl;
	}
};

struct A
{
	A()
	{
		std::cout << __PRETTY_FUNCTION__ << std::endl;
	}
	~A()
	{
		std::cout << __PRETTY_FUNCTION__ << std::endl;
	}
	A(const A &other)
	{
		std::cout << __PRETTY_FUNCTION__ << std::endl;
	}
	A(A &&other) noexcept
	{
		std::cout << __PRETTY_FUNCTION__ << std::endl;	
	}
	A& operator=(const A &other)
	{
		std::cout << __PRETTY_FUNCTION__ << std::endl;
		if(this == &other)
		{
			return *this;
		}

		return *this;
	}
	A& operator=(A &&other) noexcept
	{
		std::cout << __PRETTY_FUNCTION__ << std::endl;
		if(this == &other)
		{
			return *this;
		}

		return *this;
	}
};

struct B
{
	B()
	{
		std::cout << __PRETTY_FUNCTION__ << std::endl;
	}
	~B()
	{
		std::cout << __PRETTY_FUNCTION__ << std::endl;
	}
	B(const B &other)
	{
		std::cout << __PRETTY_FUNCTION__ << std::endl;
	}
	B(B &&other) noexcept
	{
		std::cout << __PRETTY_FUNCTION__ << std::endl;	
	}
	B& operator=(const B &other)
	{
		std::cout << __PRETTY_FUNCTION__ << std::endl;
		if(this == &other)
		{
			return *this;
		}

		return *this;
	}
	B& operator=(B &&other) noexcept
	{
		std::cout << __PRETTY_FUNCTION__ << std::endl;
		if(this == &other)
		{
			return *this;
		}

		return *this;
	}
};

union UDT
{
	A a;
	B b;	
	std::string s;
	// Because of A & B have user defined default constructors the UDT default counstructor will be deleted and should be explicitly created. default keyword can not be used.
	UDT()
	{
	}

	// Because of A & B have user defined default destructors the UDT default destructor will be deleted and should be explicitly created.
	~UDT()
	{
	}
};

int main()
{
	Test t;
	cout << t.ch << endl;
	cout << t.x << endl;

	t.x = 1000;
	cout << t.ch << endl;

	cout << "sizeof(t)=" << sizeof(t) << endl;

	//
	using namespace std::string_literals;
	UDT udt;
	// Can not use the next line, because s no created (union share memory for some of different types and non of them initialzied, only the memory allocated to the largest one
	//udt.s = "Some string"s;
	//Therefore the only way to initialize user-defined type ins ide a union is a : new(udt.s) - whcih initialize a memory (but not allocate) - it already allocated.
	new(&udt.s) std::string{"Hello"};

	new(&udt.a) A{};
	//new(&udt.a) B{};

	udt.a.~A();
	
	
	return 0;
}
