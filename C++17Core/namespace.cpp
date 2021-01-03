// Single-line comment
/*
 * Multiple line comment
 */

#include <iostream>

using namespace std;

namespace A
{
	namespace B
	{
		namespace C
		{
			void foo() {}
		}
	}
}

namespace A::B::C
{
	void bar() {}
}

int main()
{
	A::B::C::foo();
	using A::B::C::bar;
	bar();

	using namespace A::B::C;
	foo();

	return 0;
}
