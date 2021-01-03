// Single-line comment
/*
 * Multiple line comment
 */

#include <iostream>
// Macro
#define RED_COLOR 0

using namespace std;

enum Color {RED, GREEN, BLUE};


// Symbolic const
const int GREEN_COLOR = 1;

void fill_color(int color)
{
	if(color == RED)
	{
		// Paint wih red color
	}
	else if(color == GREEN)
	{
		// Paint with green color
	}
}

void fill_color_enum(Color color)
{
	if(color == RED)
	{
		cout << "RED" << endl;
	}
	else if(color == BLUE)
	{
		cout << "BLUE" << endl;
	}
	else if(color == GREEN)
	{
		cout << "GREEN" << endl;
	}
}



int main()
{
	// Wrong way
	fill_color(RED_COLOR);
	fill_color(GREEN_COLOR);
	// Unacceptable value can be passed:
	fill_color(6);

	// Right way
	Color color = GREEN;
	fill_color_enum(color);
	fill_color_enum(RED);
	fill_color_enum(static_cast<Color>(2));


	return 0;
}
