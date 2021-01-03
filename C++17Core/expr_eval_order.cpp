// Single-line comment
/*
 * Multiple line comment
 */

#include <iostream>

using namespace std;

class EvaluationOrder
{
public:
	EvaluationOrder& First(int)
	{
		cout << __PRETTY_FUNCTION__ << endl;
		return *this;
	}

	EvaluationOrder& Second(int)
	{
		cout << __PRETTY_FUNCTION__ << endl;
		return *this;
	}
};


int FirstSubExpression(int)
{
	cout << __PRETTY_FUNCTION__ << endl;
	return 0;
}

int SecondSubExpression(int)
{
	cout << __PRETTY_FUNCTION__ << endl;
	return 0;
}

int main()
{
	EvaluationOrder eo;
	eo.First(FirstSubExpression(0)).Second(SecondSubExpression(0));
	return 0;
}
