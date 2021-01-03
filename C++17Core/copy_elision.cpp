// Single-line comment
/*
 * Multiple line comment
 */

#include <iostream>

//#define DELETE_COPY_MOVE

using namespace std;

class Number
{
public:
	Number(int value)
	{
		cout << "Parametrized ctor: " << __PRETTY_FUNCTION__ << endl;
	}
#ifdef DELETE_COPY_MOVE
	Number (const Number &) = delete;
	Number (Number &&) = delete;
#else
	Number(const Number &)
	{
		cout << "Copy ctor: " << __PRETTY_FUNCTION__ << endl;
	}
	Number(Number &&)
	{
		cout << "Move ctor: " << __PRETTY_FUNCTION__ << endl;
	}
#endif
};

void foo(Number n)
{
}

Number Create()
{
	/*Number n{0};

	return n;*/

	return Number{0};
}

template<typename T, typename ...Args>
	T Create(Args &&...args)
	{
		return T{args...};
	}
	

int main()
{
	Number n0 {Number{5}};
	Number n1 = Number{3};

	foo(Number{3});

	auto n2 = Create();

	auto n3 = Create<Number>(0);

	return 0;
}
