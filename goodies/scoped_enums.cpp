// Single-line comment
/*
 * Multiple line comment
 */

#include <iostream>

using namespace std;

enum class Color {RED, GREEN, BLUE};

void fill_color_enum(Color color)
{
	if(color == Color::RED)
	{
		cout << "RED" << endl;
	}
	else if(color == Color::BLUE)
	{
		cout << "BLUE" << endl;
	}
	else if(color == Color::GREEN)
	{
		cout << "GREEN" << endl;
	}
}

enum class TrafficLight {RED, YELLOW, GREEN};

// Underlined type can be any integral type

enum class PlanType : char {A='a', B, C};

// Assign values to enumerations

enum class OtherColor : long {RED = 5, GREEN = 15, BLUE};

int main()
{
	// Right way
	Color color = Color::GREEN;
	fill_color_enum(color);
	fill_color_enum(Color::RED);
	fill_color_enum(static_cast<Color>(2));
	int x = static_cast<int>(Color::GREEN);
	cout << x << endl;


	return 0;
}
