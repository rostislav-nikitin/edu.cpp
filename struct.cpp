// Single-line comment
/*
 * Multiple line comment
 */

#include <iostream>

using namespace std;

struct Point
{
	int x;
	int y;
};

void draw_line(int x1, int y1, int x2, int y2)
{
}

void draw_line(Point start, Point end)
{
	cout << start.x << endl;
}

int main()
{
	Point point;
	point.x = 10;

	draw_line(point, point);
	return 0;
}
