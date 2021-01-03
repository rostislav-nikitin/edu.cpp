// Single-line comment
/*
 * Multiple line comment
 */

#include <iostream>

using namespace std;

class Animal
{
	public:
		void eat()
		{
			cout << "Animal eating" << endl;
		}
		void run()
		{
			cout << "Animal running" << endl;
		}
		void speak()
		{
			cout << "Animal speaking" << endl;
		}
};


class Dog : public Animal
{
	public:
		void eat()
		{
			cout << "Dog eating meat" << endl;
		}
		void speak()
		{
			cout << "Dog barking" << endl;
		}
};

int main()
{
	Animal a;
	a.eat();

	Dog d;
	d.eat();
	d.run();
	d.speak();

	return 0;
}
