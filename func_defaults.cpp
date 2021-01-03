// Single-line comment
/*
 * Multiple line comment
 */

#include <iostream>

using namespace std;

const int DefaultX = -1;
const int DefaultY = -1;
const int DefaultWidth = -1;
const int DefaultHeight = -1;

void create_window(const char *title, 
	int x = DefaultX, 
	int y = DefaultY, 
	int width = DefaultWidth, 
	int height = DefaultHeight);

int main()
{
	create_window("GEdit", 10, 20);
	create_window("GEdit", 10, 20, 800, 600);

	return 0;
}

void create_window(const char *title, 
	int x, 
	int y, 
	int width, 
	int height)
{
	cout << "Title :" << title << endl;
	cout << "x :" << x << endl;
	cout << "y :" << y << endl;
	cout << "with :" << width << endl;
	cout << "heigth :" << height << endl;
}

