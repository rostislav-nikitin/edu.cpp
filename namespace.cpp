// Single-line comment
/*
 * Multiple line comment
 */

#include <iostream>

using namespace std;

namespace avg
{
	float calculate(float x, float y)
	{
		return (x + y) / 2;
	}
}

namespace basic
{
	float calculate(float x, float y)
	{
		return x + y;
	}
}

namespace sort
{
	void quick_sort()
	{
	}

	void insertion_sort()
	{
	}

	void merge_sort()
	{
	}
	namespace comparison
	{
		void less()
		{
		}

		void greater()
		{
		}
	}
}

// Visible only inside a scope where namespace is declared (there only inside a file)
namespace
{
	void internal_function()
	{
	}
}

int main()
{
	internal_function();

	cout << avg::calculate(3.0f, 5.1f) << endl;
	cout << basic::calculate(3.0f, 5.1f) << endl;

	using namespace avg;
	cout << calculate(3.0f, 5.1f) << endl;

	cout << basic::calculate(3.0f, 5.1f) << endl;

	sort::comparison::less();

	return 0;
}
