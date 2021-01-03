// Single-line comment
/*
 * Multiple line comment
 */

#include <iostream>

class Integer
{
	private:
		int value{0};
	public:
		/*Integer()
		{
			value = 0;
		}*/

		// Because of parametrized constructor specified, default constructor will not sentisized by the compiler
		Integer(int value)
		{
			this->value = value;
		}
		// But in C++17 you can explicitly ask compiler to sentisize them (also copy constructor, deconstructor, assignement: all the ones could be sentisized)
		Integer() = default;

		// Do NOT sentisize copy construnctor
		Integer(const Integer &) = delete;
		// delete can be applied to the any function
		// overloads
		void set_value(int value)
		{
			this->value = value;
		}

		void set_value(float) = delete;

};

using namespace std;

int main()
{
	Integer i1;
	Integer i2(3);
	Integer i3(i1);
	i1.set_value(5);
	i1.set_value(61.25f);
	

	return 0;
}
